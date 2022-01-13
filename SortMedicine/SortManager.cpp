#include "SortManager.h"

namespace Sorting {

	SortManager::SortManager(ISortBoxesAccess* _access)
	{
		access = _access;
	}
	std::vector<Models::SortBox> SortManager::GetBoxes()
	{
		return access->GetBoxes();;
	}
	void SortManager::AddPillsToBox(const int boxID, const int amount)
	{
		access->AddPillsToBox(boxID, amount);
	}
	void SortManager::RemovePillsFromBox(const int boxID, const int amount)
	{
		access->RemovePillsFromBox(boxID, amount);
	}
	void SortManager::AddPillToBox(const int boxID, Models::Pill pill, const int amount)
	{
		Models::SortBox* box = access->GetBoxWithThePillID(pill.GetID());

		// there is no box with that pill
		if (box == nullptr) {

			// see if there is a place for the box
			int freeBox = access->GetEmptyBox();

			// TODO: change throw to something diffrent
			if (freeBox == -1)
				throw "No empty box";


			access->AddPillToBox(freeBox, pill, amount);
		}
		else
		{
			// box found with that pill
			access->AddPillsToBox(box->GetBoxId(), amount);

			delete box;
		}
	}
}