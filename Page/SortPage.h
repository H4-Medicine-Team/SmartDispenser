#pragma once
#include <iostream>

#include "../Gui/Page.h"
#include "../Gui/Button.h"
#include "../Models/SortModels/SortBox.h"
#include "../SortMedicine/ISortDataManager.h"

namespace Page {

	class SortPage : public Gui::Page
	{
	public:
		SortPage();

	public:
		Sorting::ISortDataManager* m_dataManager;
	};
}
