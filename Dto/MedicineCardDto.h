#pragma once
#include <string>
#include <time.h>

namespace Dto {
	struct MedicineDto {
		int id;
		std::string name;
		tm time;
		int amount;
	};
}