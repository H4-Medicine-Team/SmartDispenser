#include "Raylib.h"
#include "Gui/PageHandler.h"
#include "Gui/Button.h"

#include <iostream>

const static int screen_width = 800;
const static int screen_height = 450;

static void medCall(Gui::Button* btn, bool isPressed) {
    Gui::ButtonStyle style = btn->GetStyle();

    if (isPressed)
        style.textColor = { 0, 255, 0, 255 };
    else
        style.textColor = { 0, 0, 0, 255 };

    btn->SetStyle(style);
}

class PageE : public Gui::Page {
public:
    PageE() {
        // Styles
        Gui::ButtonStyle bStyle = {
            {255, 0, 0, 255},
            {0, 0, 0, 255},
            20
        };

        Vector2 buttonSize = { 300, 200 };


        // GUi
        Gui::Button* medicineCardBtn = new Gui::Button("Medicinkort", { 400, 225 }, buttonSize, bStyle);

        // Add
        Add(medicineCardBtn);
        
        // Callbacks
        medicineCardBtn->SetClickCallback(medCall);
    }
};

int main(void)
{
    InitWindow(screen_width, screen_height, "raylib [core] example - basic window");
    SetGesturesEnabled(GESTURE_TAP);
 
    Gui::PageHandler::Get().Add(new PageE(), "one");
    Gui::PageHandler::Get().SetPage("one");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground({ 255, 255, 255, 255 });
        Gui::PageHandler::Get().Loop();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}