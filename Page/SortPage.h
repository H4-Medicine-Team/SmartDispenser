#pragma once
#include <iostream>

#include "../Gui/Page.h"
#include "../Gui/Button.h"
#include "../SortMedicine/SortManager.h"
#include "../Models/SortModels/SortBox.h"

#include "../SortMedicine/SortDataCaller.h"
//#include "../MedicineSorting/SortDataFetcher.h"

namespace Page {

	class SortPage : public Gui::Page
	{
	public:
		SortPage();
	};
}