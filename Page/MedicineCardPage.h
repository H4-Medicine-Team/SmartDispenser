#pragma once
#include "../Gui/Page.h"
#include "../DataAccess/LocalDb.h"
#include "../Dto/MedicineCardDto.h"
#include "../Gui/MedicineButton.h"
#include "../Gui/ScrollView.h"

namespace Page {
	class MedicineCardPage : public Gui::Page {
	public:
		MedicineCardPage();
		~MedicineCardPage();

	private:
		void OnMedicineClick(Gui::MedicineButton* btn, const Vector2& mousePos, bool isPressed);

		void GetMedicineData();

	private:
		Gui::ScrollView* m_ScrollView;
		DataAccess::LocalDb m_Database;
		std::vector<Dto::MedicineDto>* m_Data;
	};
}