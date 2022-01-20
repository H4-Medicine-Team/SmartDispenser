#pragma once
#include <iostream>

#include "../Gui/Button.h"
#include "../Models/SortModels/SortBox.h"
#include "../SortMedicine/ISortDataManager.h"
#include "../SortMedicine/DispenserController.h"
#include "../SortMedicine/SortManager.h"
#include "../DataAccess/SortDataCaller.h"
#include "../Gui/PageHandler.h"
#include "../Page/MainPage.h"
namespace Page {

	class SortPage : public Gui::Page
	{
	public:
		SortPage();
		~SortPage();
		

		void onBoxOneClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed); 
		void onBoxTwoClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed);
		void onBoxThreeClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed);
	private:
		Sorting::ISortDataManager* m_sortManager;
	};

}

