#pragma once
#include <TestFramework.h>

#include "../../Gui/EditButton.h"

static bool EqualVector(const Vector2& v1, const Vector2& v2) {
	return (v1.x == v2.x && v1.y == v2.y);
}

TESTCLASS_(EditButtonShould, HaveSamePositionWhenCreated) {
	// Arrange
	Vector2 expectedPos = { 0, 0 };
	Vector2 btnPos;
	auto btn = Gui::EditButton("Test", "EditTest", { 0, 0 }, {100, 100});

	// Act
	btnPos = btn.GetPos();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCLASS_(EditButtonShould, HaveCorrectCenterPosition) {
	// Arrange
	Vector2 expectedPos = { 50, 50 };
	Vector2 btnPos;
	auto btn = Gui::EditButton("Test", "EditTest", { 0, 0 }, { 100, 100 });

	// Act
	btnPos = btn.GetCenter();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCLASS_(EditButtonShould, IsDefaultVisible) {
	// Arrange
	bool expected = true;
	bool actual;
	auto btn = Gui::EditButton("Test", "EditTest", { 0, 0 }, { 100, 100 });

	// Act
	actual = btn.IsVisible();

	// Assert
	ASSERT(expected == actual);
};

TESTCLASS_(EditButtonShould, TextIsActual) {
	// Arrange
	std::string expected = "EditTest";
	std::string actual;
	auto btn = Gui::EditButton("Test", "EditTest", { 0, 0 }, { 100, 100 });

	// Act
	actual = btn.GetText();

	// Assert
	ASSERT(expected == actual);
};

TESTCLASS_(EditButtonShould, SizeIsActual) {
	// Arrange
	Vector2 expected = { 100, 100 };
	Vector2 actual;
	auto btn = Gui::EditButton("Test", "EditTest", { 0, 0 }, { 100, 100 });

	// Act
	actual = btn.GetSize();

	// Assert
	ASSERT(EqualVector(expected, actual));
};