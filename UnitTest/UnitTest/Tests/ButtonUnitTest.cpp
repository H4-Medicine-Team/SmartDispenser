#pragma once
#include <TestFramework.h>
#include "../../Gui/Button.h"

static bool EqualVector(const Vector2& v1, const Vector2& v2) {
	return (v1.x == v2.x && v1.y == v2.y);
}

TESTCASE(ButtonShould, HaveSamePositionWhenCreated) {
	// Arrange
	Vector2 expectedPos = {0, 0};
	Vector2 btnPos;
	auto btn = Gui::Button("Test", {0, 0}, { 100, 100 });

	// Act
	btnPos = btn.GetPos();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCASE(ButtonShould, HaveCorrectCenterPosition) {
	// Arrange
	Vector2 expectedPos = { 50, 50 };
	Vector2 btnPos;
	auto btn = Gui::Button("Test", {0, 0}, { 100, 100 });

	// Act
	btnPos = btn.GetCenter();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCASE(ButtonShould, IsDefaultVisible) {
	// Arrange
	bool expected = true;
	bool actual;
	auto btn = Gui::Button("Test", { 0, 0 }, { 100, 100 });

	// Act
	actual = btn.IsVisible();

	// Assert
	ASSERT(expected == actual);
};

TESTCASE(ButtonShould, TextIsActual) {
	// Arrange
	std::string expected = "Test";
	std::string actual;
	auto btn = Gui::Button("Test", { 0, 0 }, { 100, 100 });

	// Act
	actual = btn.GetText();

	// Assert
	ASSERT(expected == actual);
};

TESTCASE(ButtonShould, SizeIsActual) {
	// Arrange
	Vector2 expected = { 100, 100 };
	Vector2 actual;
	auto btn = Gui::Button("Test", { 0, 0 }, { 100, 100 });

	// Act
	actual = btn.GetSize();

	// Assert
	ASSERT(EqualVector(expected, actual));
};