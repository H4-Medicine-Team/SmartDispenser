#pragma once

#include <string>
#include <sqlite3.h>
#include <functional>
#include <ctime>

#include "IMedicineCardAccess.h"

namespace DataAccess {
	class LocalDb : public IMedicineCardAccess
	{
	public:
		/*
		* Opens a connection to the specific database and creates the table if they do not exists
		*/
		LocalDb();

		/*
		* Closes the connection
		*/
		~LocalDb();

	public:
		std::vector<Dto::MedicineDto>* GetMedicineCard() override;
		virtual bool InsertMedicine(const Dto::MedicineDto& medicine) override;

	private:
		/*
		* Open a connection to the local database
		*/
		bool Open();

		/*
		* Close the connection to the database
		*/
		void Close();

		/*
		* Creates the tables if they exists
		*/
		bool CreateTables();

		/*
		* Converts a time to the full date time specification.
		*/
		std::string TimeToString(const tm* time);

		/*
		* Converts a string to the tm struct with the format "%c" see strptime.
		*/
		tm StringToTime(const std::string& time);

	private:
		const std::string m_DbName;
		const std::string m_TableName;
		sqlite3* m_DbHandle;
	};
}