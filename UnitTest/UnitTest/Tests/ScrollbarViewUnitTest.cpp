#pragma once
#include <TestFramework.h>
#include "../../Gui/ScrollView.h"

static bool EqualVector(const Vector2& v1, const Vector2& v2) {
	return (v1.x == v2.x && v1.y == v2.y);
}

TESTCASE(ScrollBarView, HaveSamePositionWhenCreated) {
	// Arrange
	Vector2 expectedPos = { 0, 0 };
	Vector2 btnPos;
	auto btn = Gui::ScrollView({ 0, 0 }, { 100, 100 }, { 50, 50 });

	// Act
	btnPos = btn.GetPos();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCASE(ScrollBarView, HaveCorrectCenterPosition) {
	// Arrange
	Vector2 expectedPos = { 50, 50 };
	Vector2 btnPos;
	auto btn = Gui::ScrollView({ 0, 0 }, { 100, 100 }, { 50, 50 });

	// Act
	btnPos = btn.GetCenter();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

TESTCASE(ScrollBarView, IsDefaultVisible) {
	// Arrange
	bool expected = true;
	bool actual;
	auto btn = Gui::ScrollView({ 0, 0 }, { 100, 100 }, { 50, 50 });

	// Act
	actual = btn.IsVisible();

	// Assert
	ASSERT(expected == actual);
};

TESTCASE(ScrollBarView, SizeIsActual) {
	// Arrange
	Vector2 expected = { 100, 100 };
	Vector2 actual;
	auto btn = Gui::ScrollView({ 0, 0 }, { 100, 100 }, { 50, 50 });

	// Act
	actual = btn.GetSize();

	// Assert
	ASSERT(EqualVector(expected, actual));
};