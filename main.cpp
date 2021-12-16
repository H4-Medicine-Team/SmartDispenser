#include "Raylib.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    Vector2 touchPosition = { 0, 0 };
    Rectangle touchArea = { 220, 10, 800 - 230.0f, 450 - 20.0f };

    int currentGesture = GESTURE_NONE;
    int lastGesture = GESTURE_NONE;

    Vector2 start = {200, 200};

    SetGesturesEnabled(GESTURE_TAP);

    while (!WindowShouldClose())
    {
        currentGesture = GetGestureDetected();
        touchPosition = GetTouchPosition(0);

        printf("x: %3.1f y: %3.1f touch: %d\n", touchPosition.x, touchPosition.y, currentGesture);

        if (CheckCollisionPointRec(touchPosition, touchArea) && (touchPosition.x > 0 && touchPosition.y > 0))
        {
            start = Vector2{ touchPosition.x, touchPosition.y };
        }

        BeginDrawing();
        ClearBackground(Color{10,250,50,255});
        DrawRectangle(touchArea.x, touchArea.y, touchArea.width, touchArea.height, RED);
        DrawText("Congrats! You created your first window!", start.x, start.y, 20, Color{100,50,250,255});
        EndDrawing();


    }

    CloseWindow();

    return 0;
}