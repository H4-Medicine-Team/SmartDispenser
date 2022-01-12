#pragma once
#include "../SortMedicine/SortDataCaller.h"
#include "ISortBoxesAccess.h"
#include "ISortDataManager.h"

namespace Sorting {

	class SortManager : public ISortDataManager
	{

	public:
		SortManager() = default;
		SortManager(ISortBoxesAccess* _access);

	private:
		ISortBoxesAccess* access;

		// Inherited via ISortDataManager
		virtual std::vector<Models::SortBox> GetBoxes() override;
		virtual void AddPillsToBox(const int boxID, const int amount) override;
		virtual void RemovePillsFromBox(const int boxID, const int amount) override;
		virtual void AddPillToBox(const int boxID, Models::Pill pill, const int amount) override;
	};
}

