#pragma once
#include <vector>
#include "../Models/SortModels/SortBox.h"

namespace Sorting {

	class ISortBoxesAccess
	{
	public:

		/*
		* Retrieves the sorting boxes
		*/
		virtual std::vector<Models::SortBox> GetBoxes() = 0;

		virtual Models::SortBox* GetBox(const int boxID) = 0;

		/*
		* Inserts pill amount of box in case of a refill
		*/
		virtual void AddPillsToBox(const int boxID, const int amount) = 0;

		/*
		* Remove a pill from the box after it was released to user
		*/
		virtual void RemovePillsFromBox(const int boxID, const int amount) = 0;

		/*
		* Adds a pill to a box when user insert a new pill
		*/
		virtual void AddPillToBox(const int boxID, Models::Pill pill, const int amount) = 0;

		/*
		* Gets the box that contains the pill id 
		*/
		virtual Models::SortBox* GetBoxWithThePillID(const int pillId) = 0;

		/*
		* Returns id of an empty box
		*/
		virtual int GetEmptyBoxId() = 0;
	};
}