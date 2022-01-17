#pragma once
#include <iostream>

#include "../Gui/Page.h"
#include "../Gui/Button.h"
#include "../Models/SortModels/SortBox.h"
#include "../SortMedicine/ISortDataManager.h"
#include "../SortMedicine/DispenserController.h"
#include "../SortMedicine/SortManager.h"
#include "../DataAccess/SortDataCaller.h"

namespace Page {

	class SortPage : public Gui::Page
	{
	public:
		SortPage();
		~SortPage();
		
		void boxOneClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed); 
		void boxTwoClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed);
		void boxThreeClicked(Gui::Button* btn, const Vector2& mousePos, bool isPressed);
	private:
		Sorting::ISortDataManager* m_sortManager;
	};

}

