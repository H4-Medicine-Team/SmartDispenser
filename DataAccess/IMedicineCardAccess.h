#pragma once
#include "../Dto/MedicineCardDto.h"
#include <vector>

namespace DataAccess {
	class IMedicineCardAccess {
	public:

		/*
		* Retrieves the medicine data from local db
		*/
		virtual std::vector<Dto::MedicineDto>* GetMedicineCard() = 0;

		/*
		* Inserts a single medicine into the local db
		* Id is not taken into account
		*/
		virtual bool InsertMedicine(const Dto::MedicineDto& medicine) = 0;
	};
}