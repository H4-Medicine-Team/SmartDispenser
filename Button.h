#pragma once
#include "Gui.h"
#include "RayLib.h"

class Button : Gui
{
public:
	void Start() override;
	void Update() override;
	void Draw() override;
	void OnClick();

	Button(Vector2 vector2,int height,int width, Color color) {
		this->Vector = vector2;
		this->Height = height;
		this->Width = width;
		this->ButtonColor = color;
	};

	int GetHeight() {
		return Height;
	}

	int GetWidth() {
		return Width;
	}

	Vector2 GetVector() {
		return Vector;
	}

	Color GetButtonColor() {
		return ButtonColor;
	}

private:
	Vector2 Vector;
	Color ButtonColor;
	int Height;
	int Width;
};