#pragma once
#include <TestFramework.h>
#include "../../DataAccess/SortDataCallerMock.h"

TESTCASE(SortDataCaller, RetrievesBoxes) 
{
	// Arrange
	int amountOfBoxes = 0;
	int expectedBoxesRetrived = 3;
	auto caller = DataAccess::SortDataCallerMock();

	// Act
	amountOfBoxes = caller.GetBoxes().size();

	// Assert
	ASSERT(expectedBoxesRetrived == amountOfBoxes);
}

TESTCASE(SortDataCaller, FailsToRetrievesBoxById)
{
	// Arrange
	int boxId = 420;
	Models::SortBox* box = nullptr;

	auto caller = DataAccess::SortDataCallerMock();

	// Act
	box = caller.GetBox(boxId);

	// Assert
	ASSERT(box == nullptr);

	delete box;
}

TESTCASE(SortDataCaller, RetrievesBoxById)
{
	// Arrange
	int boxId = 0;
	Models::SortBox* box = nullptr;

	auto caller = DataAccess::SortDataCallerMock();

	// Act
	box = caller.GetBox(boxId);

	// Assert
	ASSERT(box != nullptr);

	delete box;
}


TESTCASE(SortDataCaller, RetrievesBoxByPillId)
{
	// Arrange
	int pillId = 0;
	Models::SortBox* box;

	auto caller = DataAccess::SortDataCallerMock();

	// Act
	box = caller.GetBoxWithThePillID(pillId);

	// Assert
	ASSERT(box != nullptr);

	delete box;
}

TESTCASE(SortDataCaller, FailsToRetrievesBoxByPillId)
{
	// Arrange
	int pillId = 124512;
	Models::SortBox* box;

	auto caller = DataAccess::SortDataCallerMock();

	// Act
	box = caller.GetBoxWithThePillID(pillId);

	// Assert
	ASSERT(box == nullptr);

	delete box;
}