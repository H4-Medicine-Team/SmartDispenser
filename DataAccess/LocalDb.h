#pragma once

#include <string>
#include <sqlite3.h>
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
		virtual std::vector<Dto::MedicineDto>* GetMedicineCard() override;
		virtual void InsertMedicine(const Dto::MedicineDto& medicine) override;
		virtual void RemoveMedicine(const Dto::MedicineDto& medicine) override;
		virtual void EditMedicine(const Dto::MedicineDto& medicine) override;

	protected:
		virtual void Open() override;
		virtual void Close() override;

	private:
		/*
		* Creates the tables if they exists
		*/
		void CreateTables();

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