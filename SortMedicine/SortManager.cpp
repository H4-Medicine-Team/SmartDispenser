#include "SortManager.h"

namespace Sorting {

	SortManager::SortManager(ISortBoxesAccess* _access, Sorting::IControllDispenser* _dispenserController)
	{
		m_access = _access;
		m_dispenserController = _dispenserController;
	}
	SortManager::~SortManager()
	{
		delete m_access;
		delete m_dispenserController;
	}

	void SortManager::RotateMotor(const int boxId) {

		// Test data
		const int maxBoxes = 3;

		// width in cm
		const int boxWidth = 5;

	
		// get current posion of the motor
		int currentDegress = m_dispenserController->GetCurrentDegrees();


		// Calculate the distance the motor has to move 
		int cmMove = 0;

		m_dispenserController->Update(cmMove);
	}

	void SortManager::SetupDispenserController()
	{
		m_dispenserController->Setup();
	}

	std::vector<Models::SortBox> SortManager::GetBoxes()
	{
		return m_access->GetBoxes();;
	}
	void SortManager::AddPillsToBox(const int boxID, const int amount)
	{
		m_access->AddPillsToBox(boxID, amount);
	}
	void SortManager::RemovePillsFromBox(const int boxID, const int amount)
	{
		m_access->RemovePillsFromBox(boxID, amount);
	}
	void SortManager::AddPillToBox(const int boxID, Models::Pill pill, const int amount)
	{
		Models::SortBox* box = m_access->GetBoxWithThePillID(pill.GetID());

		// there is no box with that pill
		if (box == nullptr) {

			// see if there is a place for the box
			int freeBox = m_access->GetEmptyBoxId();

			// There is no empty place for the pill
			if (freeBox == -1)
				throw "No empty box";

			m_access->AddPillToBox(freeBox, pill, amount);
		}
		else
		{
			// box found with that pill
			m_access->AddPillsToBox(box->GetBoxId(), amount);

			delete box;
		}
	}
}