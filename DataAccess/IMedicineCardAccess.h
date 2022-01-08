#pragma once
#include "../Dto/MedicineCardDto.h"
#include <vector>

namespace DataAccess {
	class IMedicineCardAccess {
	public:

		/*
		* Retrieves the medicine data from the db
		*/
		virtual std::vector<Dto::MedicineDto>* GetMedicineCard() = 0;

		/*
		* Inserts a single medicine into the db
		* Id is not taken into account
		*/
		virtual void InsertMedicine(const Dto::MedicineDto& medicine) = 0;

		/*
		* Uses the id of the medicine to remove the medicine from the database
		*/
		virtual void RemoveMedicine(const Dto::MedicineDto& medicine) = 0;

		/*
		* Edits the content of the medicine from the id.
		*/
		virtual void EditMedicine(const Dto::MedicineDto& medicine) = 0;

	protected:
		/*
		* Opens the connection to the database
		*/
		virtual void Open() = 0;

		/*
		* closes the connection to the database
		*/
		virtual void Close() = 0;
	};
}