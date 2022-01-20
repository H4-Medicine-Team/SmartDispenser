#include "SortPage.h"


namespace Page {
// If servo is not connected, and it will be set to 1,
// the program will crash
#define SERVO_CONNECTED 1

	static void onClickBack(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {

		if (!isPressed)
			Gui::PageHandler::Get().Load<MainPage>();
	}

	SortPage::SortPage()
	{
		Gui::Button* backBtn = new Gui::Button("Back", { 10, 10 }, { 50, 35 });
		backBtn->SetClickHandler(onClickBack);

		Add(backBtn);

		Sorting::SortDataCaller* caller = new Sorting::SortDataCaller();
		Sorting::DispenserController* controller = new Sorting::DispenserController();

		m_sortManager = new Sorting::SortManager(caller, controller);

		int buttonOffSet = 160;

		Gui::Button* boxOneBtn = new Gui::Button("Open box 1", { 10, 50 }, { 140, 125 });
		boxOneBtn->SetClickHandler(std::bind(&SortPage::onBoxOneClicked, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

		Gui::Button* boxTwoBtn = new Gui::Button("Open box 2", { boxOneBtn->GetPos().x + buttonOffSet, 50 }, { 140, 125 });
		boxTwoBtn->SetClickHandler(std::bind(&SortPage::onBoxTwoClicked, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

		Gui::Button* boxThreeBtn = new Gui::Button("Open box 3", { boxTwoBtn->GetPos().x + buttonOffSet, 50 }, { 140, 125 });
		boxThreeBtn->SetClickHandler(std::bind(&SortPage::onBoxThreeClicked, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));


		Add(boxOneBtn);
		Add(boxTwoBtn);
		Add(boxThreeBtn);

		if(SERVO_CONNECTED)
			m_sortManager->SetupDispenserController();
	}

	SortPage::~SortPage()
	{
		delete m_sortManager;
	}
	void SortPage::onBoxOneClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!isPressed) {	
			if (SERVO_CONNECTED)
				m_sortManager->RotateMotor(1);
		}
	}

	void SortPage::onBoxTwoClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!isPressed) {
			if (SERVO_CONNECTED)
				m_sortManager->RotateMotor(2);
		}
	}

	void SortPage::onBoxThreeClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!isPressed) {
			if (SERVO_CONNECTED)
				m_sortManager->RotateMotor(3);
		}
	}
}
