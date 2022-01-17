#include "SortPage.h"


namespace Page {

	SortPage::SortPage()
	{
		Sorting::SortDataCaller* caller = new Sorting::SortDataCaller();
		Sorting::DispenserController* controller = new Sorting::DispenserController();

		m_sortManager = new Sorting::SortManager(caller, controller);

		int buttonOffSet = 160;

		Gui::Button* boxOneBtn = new Gui::Button("Open box 1", { 10, 10 }, { 140, 125 });
		boxOneBtn->SetClickHandler(std::bind(&SortPage::boxOneClicked, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

		Gui::Button* boxTwoBtn = new Gui::Button("Open box 2", { boxOneBtn->GetPos().x + buttonOffSet, 10 }, { 140, 125 });
		boxTwoBtn->SetClickHandler(std::bind(&SortPage::boxTwoClicked, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

		Gui::Button* boxThreeBtn = new Gui::Button("Open box 3", { boxTwoBtn->GetPos().x + buttonOffSet, 10 }, { 140, 125 });
		boxThreeBtn->SetClickHandler(std::bind(&SortPage::boxThreeClicked, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));


		Add(boxOneBtn);
		Add(boxTwoBtn);
		Add(boxThreeBtn);
	}

	SortPage::~SortPage()
	{
		delete m_sortManager;
	}
	void SortPage::boxOneClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!isPressed) {
			std::cout << "Button 0" << std::endl;
			m_sortManager->RotateMotor(0);
		}
		// open box 1
/*		std::cout << "\nBox with id 1:" << std::endl;

		auto box = caller.GetBox(1);
		std::cout << "Box id " << box.GetBoxId() << " pill amount " << box.GetPillAmount()
			<< "\n pill id:" << box.GetPill().GetID() << " Pill name: " << box.GetPill().GetName()
			<< std::endl;*/
	}
	void SortPage::boxTwoClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!isPressed) {
			std::cout << "Button 1" << std::endl;
			m_sortManager->RotateMotor(1);
		}

	}
	void SortPage::boxThreeClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!isPressed) {

			std::cout << "Button 2" << std::endl;
			m_sortManager->RotateMotor(2);
		}
	}
}
