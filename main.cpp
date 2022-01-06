#include "Raylib.h"
#include "MainPage.h"
#include "MedicineCardPage.h"

#include <iostream>


int main(void)
{

    // Create "window"
    InitWindow(800, 480, "Smd");

    // Enable gestures
    SetGesturesEnabled(GESTURE_TAP);
 
    // Add pages
    Gui::PageHandler::Get().Add(new Page::MainPage(), "main");
    Gui::PageHandler::Get().Add(new Page::MedicineCardPage(), "medicinecard");

    // Set current page
    Gui::PageHandler::Get().SetPage("medicinecard");

    // Update & draw loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground({ 255, 255, 255, 255 });
        Gui::PageHandler::Get().Loop();
        EndDrawing();
    }

    // Close "window" free resources
    CloseWindow();

    return 0;
}