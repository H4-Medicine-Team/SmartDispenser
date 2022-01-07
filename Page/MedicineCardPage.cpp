#include "MedicineCardPage.h"

#include "../Gui/Button.h"
#include "../Gui/ScrollView.h"
#include "../Gui/PageHandler.h"

#include "MainPage.h"

namespace Page {
	static void backCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {

		if (!isPressed)
			Gui::PageHandler::Get().Load<MainPage>();
	}

	MedicineCardPage::MedicineCardPage() {
		// styles
		Gui::ScrollBarStyle scrollBarStyle = {
			GRAY,
			RED
		};

		Gui::ScrollViewStyle scrollStyle = {
			{128, 128, 128, 255},
			50,
			10,
			scrollBarStyle
		};



		Gui::Button* backBtn = new Gui::Button("<--", { 10, 10 }, { 40, 25 });
		backBtn->SetClickHandler(backCallback);

		Gui::ScrollView* scrollView = new Gui::ScrollView({ 50, 50 }, { 700, 380 }, { 25, 40 }, scrollStyle);

		for (int i = 0; i < 10; i++)
		{
			scrollView->Add(new Gui::Button(std::string("Hej ") + std::to_string(i), { 0, 0 }, { 0, 0 }));
		}

		Add(scrollView);
		Add(backBtn);
	}
}