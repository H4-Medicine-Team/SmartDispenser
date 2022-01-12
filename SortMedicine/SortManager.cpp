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
	}
	void SortManager::RemovePillsFromBox(const int boxID, const int amount)
	{
	}
	void SortManager::AddPillToBox(const int boxID, Models::Pill pill, const int amount)
	{
		int freeBox = access->GetEmptyBox();

		if (freeBox == -1)
			throw "No empty box";


	}
}