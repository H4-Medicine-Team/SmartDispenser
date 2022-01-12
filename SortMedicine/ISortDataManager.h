#pragma once
#include <vector>
#include "../Models/SortModels/SortBox.h"

namespace Sorting {
	class ISortDataManager {
	public:
		virtual std::vector<Models::SortBox> GetBoxes() = 0;
		virtual void AddPillsToBox(const int boxID, const int amount) = 0;
		virtual void RemovePillsFromBox(const int boxID, const int amount) = 0;
		virtual void AddPillToBox(const int boxID, Models::Pill pill, const int amount) = 0;
	};
}