#include "LocalDb.h"

#include <time.h>

namespace DataAccess {

	LocalDb::LocalDb()
		: m_DbName("Medicine.db"),
		m_TableName("MedicineCard")
	{
		Open();
		CreateTables();
	}

	LocalDb::~LocalDb()
	{
		Close();
	}

	void LocalDb::InsertMedicine(const Dto::MedicineDto& medicine)
	{
		char* sql = new char[200];

		sprintf(sql, "INSERT INTO '%s' ('Name', 'Time', 'Amount') VALUES ('%s', '%s', '%d');",
			m_TableName.c_str(), medicine.name.c_str(), TimeToString(&medicine.time).c_str(), medicine.amount);

		int r = sqlite3_exec(m_DbHandle, sql, 0, 0, 0);

		delete sql;

		if (r != 0)
			throw "Cannot insert into medicinecard";
	}

	void LocalDb::RemoveMedicine(const Dto::MedicineDto& medicine)
	{
		char* errorMsg;

		char* sql = new char[300];
		sprintf(sql, "DELETE FROM %s (" \
			"WHERE 'Id' = %i;",
			m_TableName.c_str(), medicine.id);

		int r = sqlite3_exec(m_DbHandle, sql, 0, 0, &errorMsg);

		delete sql;

		if (r != 0)
			throw (std::string("Cannot remove data: ") + errorMsg).c_str();
	}

	void LocalDb::EditMedicine(const Dto::MedicineDto& medicine)
	{
		char* errorMsg;

		char* sql = new char[300];
		sprintf(sql, "UPDATE %s " \
			"SET 'Name' = %s, 'Time' = %s, 'Amount' = %i " \
			"WHERE 'Id' = %i;"
			, m_TableName.c_str(), medicine.name, TimeToString(&medicine.time).c_str(), medicine.amount, medicine.id);

		int r = sqlite3_exec(m_DbHandle, sql, 0, 0, &errorMsg);

		delete sql;

		if (r != 0)
			throw (std::string("Cannot edit table: ") + errorMsg).c_str();
	}

	std::vector<Dto::MedicineDto>* LocalDb::GetMedicineCard()
	{
		std::vector<Dto::MedicineDto>* list = new std::vector<Dto::MedicineDto>();

		char* sql = new char[200];
		sprintf(sql, "SELECT * FROM '%s';", m_TableName.c_str());

		sqlite3_stmt* stmt;
		int rc = sqlite3_prepare_v2(m_DbHandle, sql, -1, &stmt, NULL);
		if (rc != 0)
			throw "Could not retrieve medicinecard";

		Dto::MedicineDto dto;

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
		{
			dto.id = sqlite3_column_int(stmt, 0);
			dto.name = std::string((char*)sqlite3_column_text(stmt, 1));

			dto.time = StringToTime(std::string((char*)sqlite3_column_text(stmt, 2)));
			dto.amount = sqlite3_column_int(stmt, 3);

			list->push_back(dto);
		}

		sqlite3_finalize(stmt);

		delete sql;

		return list;
	}

	void LocalDb::Open()
	{
		int s = sqlite3_open(m_DbName.c_str(), &m_DbHandle);

		if (s != 0)
			throw "Cannot open database";
	}

	void LocalDb::Close()
	{
		sqlite3_close(m_DbHandle);
	}

	void LocalDb::CreateTables()
	{
		char* errorMsg;

		char* sql = new char[300];
		sprintf(sql, "CREATE TABLE IF NOT EXISTS %s (" \
			"Id INTEGER PRIMARY KEY," \
			"Name TEXT NOT NULL," \
			"Time DATETIME NOT NULL," \
			"Amount int NOT NULL"
			");", m_TableName.c_str());

		int r = sqlite3_exec(m_DbHandle, sql, 0, 0, &errorMsg);

		delete sql;

		if (r != 0)
			throw (std::string("Cannot create tables: ") + errorMsg).c_str();
	}

	std::string LocalDb::TimeToString(const tm* time)
	{
		auto stringTime = std::string(asctime(time));
		stringTime.pop_back();
		return stringTime;
	}

	tm LocalDb::StringToTime(const std::string& time)
	{
		tm tm{};
		strptime(time.c_str(), "%c", &tm);

		return tm;
	}
}