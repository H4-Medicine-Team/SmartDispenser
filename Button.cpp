#include "Button.h"
#include "Raylib.h"

void Button::Start()
{

}

void Button::Update()
{

}

void Button::Draw()
{
	BeginDrawing();
	DrawRectangle(GetVector().x, GetVector().y, GetWidth(), GetHeight(),GetButtonColor());
	EndDrawing();
}