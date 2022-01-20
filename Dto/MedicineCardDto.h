#pragma once
#include <string>
#include <time.h>

namespace Dto {
	/*
	* Represents the database overview.
	*/
	struct MedicineDto {
		int id;
		std::string name;
		tm time;
		int amount;
	};
}