#include "DispenserController.h"
namespace Sorting {
	DispenserController::DispenserController() : m_gpioPin(19)
	{

	}

	void DispenserController::Setup()
	{
		int setup = wiringPiSetupGpio();

		if (setup != 0)
			throw "Failed to setup";

		pinMode(GetPin(), PWM_OUTPUT);
		pwmSetMode(PWM_MODE_MS);

		pwmSetClock(192);
		pwmSetRange(2000);
	}

	void DispenserController::Update(int distance)
	{
		// Do some math to calculate the value
		int rotateValue = distance + 50;

		pwmWrite(GetPin(), rotateValue);
		delay(1000);
	}
}