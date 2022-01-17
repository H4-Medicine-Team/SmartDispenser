#pragma once
#include "../DataAccess/ISortBoxesAccess.h"
#include "ISortDataManager.h"
#include "IControllDispenser.h"

namespace Sorting {

	class SortManager : public ISortDataManager
	{

	public:
		SortManager() = default;
		SortManager(ISortBoxesAccess* _access, Sorting::IControllDispenser* _dispenserController);
		~SortManager();

	private:
		ISortBoxesAccess* m_access;

		// Inherited via ISortDataManager
		virtual std::vector<Models::SortBox> GetBoxes() override;
		virtual void AddPillsToBox(const int boxID, const int amount) override;
		virtual void RemovePillsFromBox(const int boxID, const int amount) override;
		virtual void AddPillToBox(const int boxID, Models::Pill pill, const int amount) override;
		virtual void RotateMotor(const int boxId) override;


		virtual void SetupDispenserController() override;

	};
}

