#include "SortDataCaller.h"

Sorting::SortDataCaller::SortDataCaller() : m_DbName("Sort.db")
{
	CreateTables();
}

Sorting::SortDataCaller::~SortDataCaller()
{
	SortDataCaller::Close();
}

std::vector<Sorting::Models::SortBox> Sorting::SortDataCaller::GetBoxes()
{
	SortDataCaller::Open();
	
	const char* selectQuery = "Select * from Boxes inner join Pills where Boxes.Pill_id = Pills.id";

	sqlite3_stmt* stmt;

	int rc = sqlite3_prepare_v2(m_DbHandle, selectQuery, -1, &stmt, NULL);

	if (rc != 0)
		throw "Could not retrieve boxes";

	std::vector<Models::SortBox> boxes;

	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		int boxID = sqlite3_column_int(stmt, 0);
		int boxPillAmount = sqlite3_column_int(stmt, 1);

		Models::SortBox box(boxID);

		int pillID = sqlite3_column_int(stmt, 3);
		std::string pillName = std::string((const char*)sqlite3_column_text(stmt, 4));
		std::string pillExternalID = std::string((const char*)sqlite3_column_text(stmt, 5));

		Models::Pill pill(pillName, pillID, pillExternalID);

		box.SetPill(pill, boxPillAmount);

		boxes.push_back(box);
	}

	sqlite3_finalize(stmt);

	SortDataCaller::Close();

	return boxes;
}

void Sorting::SortDataCaller::AddPillsToBox(const int boxID, const int amount)
{
	char* sql = "";

	sprintf(sql, "Update 'Boxes' set Pill_Amount = (select Pill_amount from Boxes where 'Boxes'.Id = %i) + %i where 'Boxes'.Id = %i;",
		boxID, amount, boxID);

	RunQuery(sql, "Cant add pills into box");
}

void Sorting::SortDataCaller::RemovePillsFromBox(const int boxID, const int amount)
{
	char* sql = "";

	sprintf(sql, "Update 'Boxes' set Pill_Amount = (select Pill_amount from Boxes where 'Boxes'.Id = %i) - %i where 'Boxes'.Id = %i;",
		boxID, amount, boxID);

	RunQuery(sql, "Cant remove pills into box");
}

void Sorting::SortDataCaller::AddPillToBox(const int boxID, Models::Pill pill, const int amount)
{
	char* sql = new char[200];
	char* sqlBox = new char[200];

	sprintf(sql, "INSERT or replace INTO 'Pills' ('Id', 'Name', 'External_id') VALUES (%i, '%s', '%s');",
		pill.GetID(), pill.GetName().c_str(), pill.GetExternalID().c_str());


	sprintf(sqlBox, "Update 'Boxes' set Pill_Amount = %i, Pill_Id = %i where 'Boxes'.Id = %i;",
		amount, pill.GetID(), boxID);

	
	RunQuery(sql, "Cannot insert into pills");
	RunQuery(sqlBox, "Cannot insert into pills");

	delete sql;
	delete sqlBox;
}


int Sorting::SortDataCaller::GetEmptyBox()
{
	char* sqlBox = "Select * from Boxes where 'Boxes'.Pills_Amount = 0";

	sqlite3_stmt* stmt;

	int rc = sqlite3_prepare_v2(m_DbHandle, sqlBox, -1, &stmt, NULL);

	if (rc != 0)
		throw "Could not find empty boxes";

	int boxID = -1;

	if ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		boxID = sqlite3_column_int(stmt, 0);
	}

	sqlite3_finalize(stmt);


	return boxID;
}

void Sorting::SortDataCaller::Open()
{
	int s = sqlite3_open(m_DbName.c_str(), &m_DbHandle);

	if (s != 0)
		throw "Cannot open database";
}

void Sorting::SortDataCaller::Close()
{
	sqlite3_close(m_DbHandle);
}

void Sorting::SortDataCaller::CreateTables()
{
	std::string boxSqlQuery = "CREATE TABLE IF NOT EXISTS Boxes (" \
		"Id INTEGER PRIMARY KEY," \
		"Pill_Amount int DEFAULT 0," \
		"Pill_Id int"
		");INSERT or ignore INTO 'Boxes' ('Id') VALUES(0);INSERT or ignore INTO 'Boxes' ('Id') VALUES(1);INSERT or ignore INTO 'Boxes' ('Id') VALUES(2);";

	std::string pillSqlQuery = "CREATE TABLE IF NOT EXISTS Pills (" \
		"Id INTEGER PRIMARY KEY," \
		"Name TEXT NOT NULL," \
		"External_id Text NOT NULL" \
		");";


	RunQuery(boxSqlQuery, "Cannot create table Boxes");
	RunQuery(pillSqlQuery, "Cannot create table Pills");
}

Sorting::Models::SortBox Sorting::SortDataCaller::GetBox(const int _boxID)
{
	SortDataCaller::Open();

	//const char* selectQuery = "Select * from Boxes where Boxes.Id = 1";

	char* sqlBox = new char[200];

	sprintf(sqlBox, "Select * from Boxes inner join Pills on Boxes.Id = '%i' and Boxes.pill_id = Pills.id;", _boxID);

	sqlite3_stmt* stmt;

	int rc = sqlite3_prepare_v2(m_DbHandle, sqlBox, -1, &stmt, NULL);

	if (rc != 0)
		throw "Could not retrieve boxes";

	Models::SortBox box;

	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		int boxID = sqlite3_column_int(stmt, 0);
		int boxPillAmount = sqlite3_column_int(stmt, 1);

		box.SetID(boxID);

		int pillID = sqlite3_column_int(stmt, 3);
	
		std::string pillName = std::string((const char*)sqlite3_column_text(stmt, 4));
		std::string pillExternalID = std::string((const char*)sqlite3_column_text(stmt, 5));

		Models::Pill pill(pillName, pillID, pillExternalID);
		
		box.SetPill(pill, boxPillAmount);
	}

	sqlite3_finalize(stmt);
	delete sqlBox;

	SortDataCaller::Close();
	return box;
}

Sorting::Models::SortBox* Sorting::SortDataCaller::GetBoxWithThePillID(const int pillId)
{
	char* sqlQuery = "";

	sprintf(sqlQuery, "Select * from Boxes where 'Boxes'.Pill_Id = %i", pillId);

	sqlite3_stmt* stmt;

	int rc = sqlite3_prepare_v2(m_DbHandle, sqlQuery, -1, &stmt, NULL);

	if (rc != 0)
		throw "Could not find empty boxes";


	Sorting::Models::SortBox* box = nullptr;

	if ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		int boxID = sqlite3_column_int(stmt, 0);
		box = new Sorting::Models::SortBox(boxID);
		int boxPillAmount = sqlite3_column_int(stmt, 1);

		int pillID = sqlite3_column_int(stmt, 3);

		std::string pillName = std::string((const char*)sqlite3_column_text(stmt, 4));
		std::string pillExternalID = std::string((const char*)sqlite3_column_text(stmt, 5));

		Models::Pill pill(pillName, pillID, pillExternalID);

		box->SetPill(pill, boxPillAmount);
	}

	sqlite3_finalize(stmt);


	return box;
}



void Sorting::SortDataCaller::RunQuery(std::string queryString, const char* throwMessage)
{
	SortDataCaller::Open();
	char* errorMsg;
	int queryResult = sqlite3_exec(m_DbHandle, queryString.c_str(), 0, 0, &errorMsg);

	if (queryResult != 0) {
		SortDataCaller::Close();
		throw (std::string(throwMessage) + *errorMsg).c_str();
	}

	SortDataCaller::Close();
}


