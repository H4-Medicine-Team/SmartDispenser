#pragma once

#include <string>
#include <sqlite3.h>
#include <functional>
#include <ctime>

namespace DataAccess {
	class LocalDb
	{
	public:
		LocalDb();
		~LocalDb();

	private:
		bool Open();
		void Close();

		bool CreateTables();

		bool InsertMedicineCard(const std::string& name, const time_t& time, int amount);

	private:
		const std::string m_DbName;
		sqlite3* m_DbHandle;
		std::function<int(void*, int, char**, char**)> m_ReceiveCallback;
	};
}