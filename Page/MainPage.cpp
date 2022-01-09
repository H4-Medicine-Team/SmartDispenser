#include "MainPage.h"
#include "MedicineCardPage.h"
#include <Gui/Button.h>
#include <Gui/PageHandler.h>
#include <Gui/Rectangle.h>
#include <Gui/Text.h>

#include <Gui/Keyboard.h>

namespace Page {

    static void medCall(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {
        if (!isPressed)
            Gui::PageHandler::Get().Load<MedicineCardPage>();
    }

    MainPage::MainPage() {

        Vector2 buttonSize = { 700, 400 };

        Gui::ButtonStyle style{};
        style.textStyle.fontSize = 25;

        // GUi
        Gui::Button* medicineCardBtn = new Gui::Button("Medicinkort", { 50, 25 }, buttonSize);
        medicineCardBtn->SetDefaultStyle(style);


        Add(medicineCardBtn);

        //Callbacks
        medicineCardBtn->SetClickHandler(medCall);
    }
}