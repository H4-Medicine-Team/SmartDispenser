#include "SortPage.h"


namespace Page {

	SortPage::SortPage()
	{
		Sorting::SortDataCaller* caller = new Sorting::SortDataCaller();
		Sorting::DispenserController* controller = new Sorting::DispenserController();

		m_sortManager = new Sorting::SortManager(caller, controller);

		int buttonOffSet = 160;

		Gui::Button* boxOneBtn = new Gui::Button("Open box 1", { 10, 10 }, { 140, 125 });
		boxOneBtn->SetClickHandler(std::bind(&SortPage::onBoxOneClicked, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

		Gui::Button* boxTwoBtn = new Gui::Button("Open box 2", { boxOneBtn->GetPos().x + buttonOffSet, 10 }, { 140, 125 });
		boxTwoBtn->SetClickHandler(std::bind(&SortPage::onBoxTwoClicked, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

		Gui::Button* boxThreeBtn = new Gui::Button("Open box 3", { boxTwoBtn->GetPos().x + buttonOffSet, 10 }, { 140, 125 });
		boxThreeBtn->SetClickHandler(std::bind(&SortPage::onBoxThreeClicked, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));


		Add(boxOneBtn);
		Add(boxTwoBtn);
		Add(boxThreeBtn);
	}

	SortPage::~SortPage()
	{
		delete m_sortManager;
	}
	void SortPage::onBoxOneClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!isPressed) {		
			m_sortManager->RotateMotor(0);
		}
	}

	void SortPage::onBoxTwoClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!isPressed) {
			m_sortManager->RotateMotor(1);
		}
	}

	void SortPage::onBoxThreeClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!isPressed) {
			m_sortManager->RotateMotor(2);
		}
	}
}
