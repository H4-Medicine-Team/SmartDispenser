#include "LocalDb.h"

namespace DataAccess {

	LocalDb::LocalDb()
		: m_DbName("Medicine.db") 
	{
		if (!Open())
			throw "Could not create db or create it";

		CreateTables();

		InsertMedicineCard("Johgn", time(NULL), 12);
	}

	LocalDb::~LocalDb()
	{
		Close();
	}

	bool LocalDb::Open()
	{
		int s = sqlite3_open(m_DbName.c_str(), &m_DbHandle);

		if (!s)
			return false;

		return true;
	}

	void LocalDb::Close()
	{
		sqlite3_close(m_DbHandle);
	}

	bool LocalDb::CreateTables()
	{
		const char* sql = "CREATE TABLE IF NOT EXISTS MedicineCard (" \
			"Id INT PRIMARY KEY NOT NULL," \
			"Name TEXT NOT NULL," \
			"Time DATETIME NOT NULL," \
			"Amount int NOT NULL"
			");";

		int r = sqlite3_exec(m_DbHandle, sql, 0, 0, 0);

		if (!r)
			return false;

		return true;
	}

	bool LocalDb::InsertMedicineCard(const std::string& name, const time_t& time, int amount)
	{
		char* error;

		char* sql = new char[200];
		sprintf(sql, "INSERT INTO 'MedicineCard' ('Id', 'Name', 'Time', 'Amount') VALUES ('%d', '%s', '%s', '%d');",
			0, name, std::to_string(time), amount);


		sqlite3_exec(m_DbHandle, sql, 0, 0, &error);

		return true;
	}
}