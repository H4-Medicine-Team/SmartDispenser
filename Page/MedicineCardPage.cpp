#include "MedicineCardPage.h"

#include "../Gui/Button.h"
#include "../Gui/MedicineButton.h"
#include "../Gui/ScrollView.h"
#include "../Gui/PageHandler.h"

#include "MainPage.h"

namespace Page {
	static void backCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {

		if (!isPressed)
			Gui::PageHandler::Get().Load<MainPage>();
	}

	MedicineCardPage::MedicineCardPage() {
		Gui::Button* backBtn = new Gui::Button("Back", { 10, 10 }, { 50, 35 });
		backBtn->SetClickHandler(backCallback);

		Gui::ScrollView* scrollView = new Gui::ScrollView({ 0, 50 }, { 800, 380 }, { 25, 40 });

		for (int i = 0; i < 10; i++)
		{
			scrollView->Add(new Gui::MedicineButton({}, {}));
		}

		Add(scrollView);
		Add(backBtn);
	}
}