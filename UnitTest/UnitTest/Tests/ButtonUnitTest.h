#pragma once
#include <TestFramework.h>
#include "../../Gui/Button.h"

TESTCLASS_(ButtonShould, HaveSamePositionWhenCreated) {
	// Arrange
	Vector2 expectedPos = {0, 0};
	Vector2 btnPos;
	auto btn = Gui::Button("Test", expectedPos, { 100, 100 });

	// Act
	btnPos = btn.GetPos();

	// Assert
	ASSERT(EqualVector(expectedPos, btnPos));
};

static bool EqualVector(const Vector2& v1, const Vector2& v2) {
	return (v1.x == v2.x && v1.y == v2.y);
}