#include "Raylib.h"
#include "Application/Input.h"
#include "Gui/PageHandler.h"

#include "Page/MainPage.h"

#include <iostream>


int main(void)
{

    // Create "window"
    InitWindow(800, 480, "Smd");

    // Set current page
    Gui::PageHandler::Get().Load<Page::MainPage>();

    // Update & draw loop
    while (!WindowShouldClose())
    {
        Application::Input::Get().Update();

        BeginDrawing();
        Gui::PageHandler::Get().Loop();
        EndDrawing();
    }

    // Close "window" free resources
    CloseWindow();

    return 0;
}