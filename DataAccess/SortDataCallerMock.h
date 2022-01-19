#pragma once
#include "../DataAccess/ISortBoxesAccess.h"
using namespace Sorting;

namespace DataAccess {

	class SortDataCallerMock : public ISortBoxesAccess
	{
	public:
		// Inherited via ISortBoxesAccess
		virtual std::vector<Models::SortBox> GetBoxes() override;
		virtual Models::SortBox* GetBox(const int boxID) override;
		virtual void AddPillsToBox(const int boxID, const int amount) override;
		virtual void RemovePillsFromBox(const int boxID, const int amount) override;
		virtual void AddPillToBox(const int boxID, Models::Pill pill, const int amount) override;
		virtual Models::SortBox* GetBoxWithThePillID(const int pillId) override;
		virtual int GetEmptyBoxId() override;
	};
}
