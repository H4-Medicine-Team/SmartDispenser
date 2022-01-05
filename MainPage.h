#pragma once
#include "Gui/SmdGui.h"

static void medCall(Gui::Button* btn, bool isPressed) {
    Gui::ButtonStyle style = btn->GetStyle();

    if (isPressed)
        style.textColor = { 0, 255, 0, 255 };
    else
        style.textColor = { 0, 0, 0, 255 };

    btn->SetStyle(style);

    Gui::PageHandler::Get().SetPage("medicinecard");
}

namespace Page {
	class MainPage : public Gui::Page {
    protected:
        void Start() override {
            // Styles
            Gui::ButtonStyle bStyle = {
                {255, 0, 0, 255},
                {0, 0, 0, 255},
                20
            };

            Vector2 buttonSize = { 700, 400 };

            // GUi
            Gui::Button* medicineCardBtn = new Gui::Button("Medicinkort", { 50, 25 }, buttonSize, bStyle);

            // Add
            Add(medicineCardBtn);

            // Callbacks
            medicineCardBtn->SetClickCallback(medCall);
        }
	};
}