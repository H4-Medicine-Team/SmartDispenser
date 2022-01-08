#include "Raylib.h"
#include "Application/Input.h"
#include "Gui/PageHandler.h"

#include "Page/MainPage.h"
#include <sqlite3.h>

#include <iostream>


static int c(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++)
    {
        std::cout << "result: " << argv[i] << std::endl;
    }
}

int main(void)
{

    //// Create "window"
    //InitWindow(800, 480, "Smd");

    //// Set current page
    //Gui::PageHandler::Get().Load<Page::MainPage>();

    //// Update & draw loop
    //while (!WindowShouldClose())
    //{
    //    Application::Input::Get().Update();

    //    BeginDrawing();
    //    Gui::PageHandler::Get().Loop();
    //    EndDrawing();
    //}

    //// Close "window" free resources
    //CloseWindow();

    sqlite3* db;
    char* err_msg;

    int suc = sqlite3_open("hej.db", &db);

    if (suc != 0)
        std::cout << "could not connect to db" << std::endl;

    suc = sqlite3_exec(db, "SELECT * FROM 'TEST';", c, 0, &err_msg);

    if (suc != 0)
        std::cout << err_msg << std::endl;

    while(true) {}

    return 0;
}