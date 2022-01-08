#include "MedicineCardPage.h"

#include "../Gui/Button.h"
#include "../Gui/MedicineButton.h"
#include "../Gui/ScrollView.h"
#include "../Gui/PageHandler.h"

#include "MainPage.h"

#include "../DataAccess/LocalDb.h"
#include "../Dto/MedicineCardDto.h"

namespace Page {
	static void backCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {

		if (!isPressed)
			Gui::PageHandler::Get().Load<MainPage>();
	}

	MedicineCardPage::MedicineCardPage() {
		Gui::Button* backBtn = new Gui::Button("Back", { 10, 10 }, { 50, 35 });
		backBtn->SetClickHandler(backCallback);

		Gui::ScrollView* scrollView = new Gui::ScrollView({ 0, 50 }, { 800, 380 }, { 25, 40 });

		DataAccess::LocalDb db = DataAccess::LocalDb();

		std::vector<Dto::MedicineDto>* data = db.GetMedicineCard();

		for (int i = 0; i < data->size(); i++)
		{
			auto btn = new Gui::MedicineButton({}, {});
			btn->SetData((*data)[i]);
			scrollView->Add(btn);
		}

		delete data;

		Add(scrollView);
		Add(backBtn);
	}
}