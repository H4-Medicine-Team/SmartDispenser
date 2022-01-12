#include "SortPage.h"


namespace Page {

#pragma region BUTTON_CLICK

	static void boxOneClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {
		// when mouse was released
		if (!isPressed)
		{
			// open box 1
	/*		std::cout << "\nBox with id 0:" << std::endl;

			auto box = caller.GetBox(0);
			std::cout << "Box id " << box.GetBoxId() << " pill amount " << box.GetPillAmount()
				<< "\n pill id:" << box.GetPill().GetID() << " Pill name: " << box.GetPill().GetName()
				<< std::endl;*/

		}
	}

	static void boxTwoClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {

		// when mouse was released
		if (!isPressed)
		{
			// open box 1
	/*		std::cout << "\nBox with id 1:" << std::endl;

			auto box = caller.GetBox(1);
			std::cout << "Box id " << box.GetBoxId() << " pill amount " << box.GetPillAmount()
				<< "\n pill id:" << box.GetPill().GetID() << " Pill name: " << box.GetPill().GetName()
				<< std::endl;*/

		}
	}
	static void boxThreeClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {

		// when mouse was released
		if (!isPressed)
		{
			// open box 1
		/*	std::cout << "\nBox with id 2:" << std::endl;

			auto box = caller.GetBox(2);
			std::cout << "Box id " << box.GetBoxId() << " pill amount " << box.GetPillAmount()
				<< "\n pill id:" << box.GetPill().GetID() << " Pill name: " << box.GetPill().GetName()
				<< std::endl;*/

		}
	}
#pragma endregion 

	Page::SortPage::SortPage()
	{
		int buttonOffSet = 160;

		Gui::Button* boxOneBtn = new Gui::Button("open box 1", { 10, 10 }, { 140, 125 });
		boxOneBtn->SetClickHandler(boxOneClicked);

		Gui::Button* boxTwoBtn = new Gui::Button("open box 2", { boxOneBtn->GetPos().x + buttonOffSet, 10 }, { 140, 125 });
		boxTwoBtn->SetClickHandler(boxTwoClicked);

		Gui::Button* boxThreeBtn = new Gui::Button("open box 3", { boxTwoBtn->GetPos().x + buttonOffSet, 10 }, { 140, 125 });
		boxThreeBtn->SetClickHandler(boxThreeClicked);


		Add(boxOneBtn);
		Add(boxTwoBtn);
		Add(boxThreeBtn);
	}
}
