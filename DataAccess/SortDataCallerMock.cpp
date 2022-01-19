#include "SortDataCallerMock.h"
namespace DataAccess {

	std::vector<Models::SortBox> SortDataCallerMock::GetBoxes()
	{
		std::vector<Models::SortBox> boxes;

		for (int i = 0; i < 3; i++)
		{
			Models::SortBox box(i);

			Models::Pill pill("Pill " + i, i, "Ext" + i);
			box.SetPill(pill, i * (rand() % 20));

			boxes.push_back(box);
		}

		return boxes;
	}
	Models::SortBox* SortDataCallerMock::GetBox(const int boxID)
	{
		if (boxID > 3)
			return nullptr;

		Models::SortBox* box = new Models::SortBox(boxID);

		return box;
	}
	void SortDataCallerMock::AddPillsToBox(const int boxID, const int amount)
	{
	}
	void SortDataCallerMock::RemovePillsFromBox(const int boxID, const int amount)
	{
	}
	void SortDataCallerMock::AddPillToBox(const int boxID, Models::Pill pill, const int amount)
	{
	}
	Models::SortBox* SortDataCallerMock::GetBoxWithThePillID(const int pillId)
	{
		if (pillId > 3)
			return nullptr;

		Models::SortBox* box = new Models::SortBox(0);

		Models::Pill pill("Pill " + pillId, pillId, "Ext" + pillId);
		box->SetPill(pill, 1 + (rand() % 20));


		return box;
	}
	int SortDataCallerMock::GetEmptyBoxId()
	{
		return 1;
	}
}