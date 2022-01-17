#pragma once
#include "../WiringPi/wiringPi.h"
#include "IControllDispenser.h";
#include <iostream>

namespace Sorting {

	class DispenserController : public IControllDispenser
	{
	public:
		DispenserController();
		~DispenserController() = default;


		void Setup() override;
		void Update(int distance) override;

	public:
		inline int GetPin() { return m_gpioPin; }
		inline void SetPin(int pin) { m_gpioPin = pin; }
		inline int GetCurrentPosition() { return m_currentDegrees; }
	
	private:
		int m_gpioPin = 19;
	};
}
