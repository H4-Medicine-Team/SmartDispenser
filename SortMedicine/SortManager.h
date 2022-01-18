#pragma once
#include "../DataAccess/ISortBoxesAccess.h"
#include "ISortDataManager.h"
#include "IControllDispenser.h"

namespace Sorting {

	class SortManager : public ISortDataManager
	{

	public:
		SortManager(ISortBoxesAccess* _access, Sorting::IControllDispenser* _dispenserController);
		~SortManager();

	private:
		virtual std::vector<Models::SortBox> GetBoxes() override;
		virtual void AddPillsToBox(const int boxID, const int amount) override;
		virtual void RemovePillsFromBox(const int boxID, const int amount) override;
		virtual void AddPillToBox(const int boxID, Models::Pill pill, const int amount) override;


		virtual void RotateMotor(const int boxId) override;
		virtual void SetupDispenserController() override;

	private:
		Sorting::IControllDispenser* m_dispenserController;
		Sorting::ISortBoxesAccess* m_access;

	};
}

