#pragma once
#include <vector>
#include "../Models/SortModels/SortBox.h"
#include "../SortMedicine/IControllDispenser.h"

namespace Sorting {
	class ISortDataManager {
	public:
		/*
		Retrieves a list of boxes
		*/
		virtual std::vector<Models::SortBox> GetBoxes() = 0;

		/*
		Add pill amounts to the box
		*/
		virtual void AddPillsToBox(const int boxID, const int amount) = 0;

		/*
		Remove pill amount from database
		*/
		virtual void RemovePillsFromBox(const int boxID, const int amount) = 0;

		/*
		Adds pill to the box
		*/
		virtual void AddPillToBox(const int boxID, Models::Pill pill, const int amount) = 0;

		/*
		Rotates servo motor based on the box position
		*/
		virtual void RotateMotor(const int boxId) = 0;

		/*
		Configures all setup on start on the dispenser
		*/
		virtual void SetupDispenserController() = 0;

	};
}