#include "MainPage.h"
#include "MedicineCardPage.h"
#include "SortPage.h"
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
    static void sortCall(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {
        if (!isPressed)
            Gui::PageHandler::Get().Load<SortPage>();
    }

    MainPage::MainPage() {

        Vector2 buttonSize = { 350, 200 };

        Gui::ButtonStyle style{};
        style.textStyle.fontSize = 25;

        // GUi
        Gui::Button* medicineCardBtn = new Gui::Button("Medicinkort", { 50, 25 }, buttonSize);
        medicineCardBtn->SetDefaultStyle(style);


        Add(medicineCardBtn);

        //Callbacks
        medicineCardBtn->SetClickHandler(medCall);

       

        Gui::Button* sortPageBtn = new Gui::Button("SortPage", { 50, buttonSize.y + 100 }, buttonSize);
        sortPageBtn->SetDefaultStyle(style);


        Add(sortPageBtn);

        //Callbacks
        sortPageBtn->SetClickHandler(sortCall);
    }
}