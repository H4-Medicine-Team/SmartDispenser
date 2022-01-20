#pragma once
#include <TestFramework.h>
#include "../../Gui/MedicineButton.h"

static bool EqualVector(const Vector2& v1, const Vector2& v2) {
	return (v1.x == v2.x && v1.y == v2.y);
}

TESTCASE(MedicineButtonShould, HaveSamePositionWhenCreated) {
	// Arrange
	Vector2 expectedPos = { 0, 0 };
	Vector2 btnPos;
	auto btn = Gui::MedicineButton({0, 0}, { 100, 100 });

	// Act
	btnPos = btn.GetPos();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCASE(MedicineButtonShould, HaveCorrectCenterPosition) {
	// Arrange
	Vector2 expectedPos = { 50, 50 };
	Vector2 btnPos;
	auto btn = Gui::MedicineButton({ 0, 0 }, { 100, 100 });

	// Act
	btnPos = btn.GetCenter();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCASE(MedicineButtonShould, IsDefaultVisible) {
	// Arrange
	bool expected = true;
	bool actual;
	auto btn = Gui::MedicineButton({ 0, 0 }, { 100, 100 });

	// Act
	actual = btn.IsVisible();

	// Assert
	ASSERT(expected == actual);
};

TESTCASE(MedicineButtonShould, SizeIsActual) {
	// Arrange
	Vector2 expected = { 100, 100 };
	Vector2 actual;
	auto btn = Gui::MedicineButton({ 0, 0 }, { 100, 100 });

	// Act
	actual = btn.GetSize();

	// Assert
	ASSERT(EqualVector(expected, actual));
};