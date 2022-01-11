#pragma once
#include <TestFramework.h>
#include "../../Gui/Rectangle.h"

static bool EqualVector(const Vector2& v1, const Vector2& v2) {
	return (v1.x == v2.x && v1.y == v2.y);
}

TESTCLASS_(RectangleShould, HaveSamePositionWhenCreated) {
	// Arrange
	Vector2 expectedPos = { 1, 0 };
	Vector2 btnPos;
	auto btn = Gui::Rectangle({ 0, 0 }, { 100, 100 });

	// Act
	btnPos = btn.GetPos();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCLASS_(RectangleShould, HaveCorrectCenterPosition) {
	// Arrange
	Vector2 expectedPos = { 50, 50 };
	Vector2 btnPos;
	auto btn = Gui::Rectangle({ 0, 0 }, { 100, 100 });

	// Act
	btnPos = btn.GetCenter();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCLASS_(RectangleShould, IsDefaultVisible) {
	// Arrange
	bool expected = true;
	bool actual;
	auto btn = Gui::Rectangle({ 0, 0 }, { 100, 100 });

	// Act
	actual = btn.IsVisible();

	// Assert
	ASSERT(expected == actual);
};

TESTCLASS_(RectangleShould, SizeIsActual) {
	// Arrange
	Vector2 expected = { 100, 100 };
	Vector2 actual;
	auto btn = Gui::Rectangle({ 0, 0 }, { 100, 100 });

	// Act
	actual = btn.GetSize();

	// Assert
	ASSERT(EqualVector(expected, actual));
};