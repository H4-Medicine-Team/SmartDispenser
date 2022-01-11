#pragma once

#include <vector>
#include <sqlite3.h>

#include "../SortMedicine/ISortBoxesAccess.h"
#include "../Models/SortModels/SortBox.h"

namespace Sorting {
	class SortDataCaller : public Sorting::ISortBoxesAccess
	{
	public:
		SortDataCaller();
		~SortDataCaller();


	public:
		// Inherited via ISortBoxesAccess
		virtual std::vector<Models::SortBox> GetBoxes() override;
		virtual Models::SortBox GetBox(const int boxID) override;
		virtual void AddPillsToBox(const int boxID, const int amount) override;
		virtual void RemovePillsFromBox(const int boxID, const int amount) override;
		virtual void AddPillToBox(const int boxID, Models::Pill pill, const int amount) override;
		virtual int GetEmptyBox() override;
		virtual void Open() override;
		virtual void Close() override;


	private:
		/*
		* Creates the tables if they exists
		*/
		void CreateTables();

		void RunQuery(std::string queryString, const char* throwMessage);

		const std::string m_DbName;
		sqlite3* m_DbHandle;

		// Inherited via ISortBoxesAccess
	};
}

