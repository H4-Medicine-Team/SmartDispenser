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
		/*
		Gets designated pin that is connected to the servo motor
		*/
		inline int GetPin() { return m_gpioPin; }

		/*
		Sets the designated pin
		*/
		inline void SetPin(int pin) { m_gpioPin = pin; }
	
	private:
		/*
		Default gpio pin is 19, on Raspbery pi 4 b
		*/
		int m_gpioPin = 19;
	};
}
