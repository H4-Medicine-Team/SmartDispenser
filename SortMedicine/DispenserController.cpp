#include "DispenserController.h"
namespace Sorting {
	DispenserController::DispenserController() : m_gpioPin(19)
	{

	}

	void DispenserController::Setup()
	{
		// setupgpio will error code if it doesnt setup
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
		// Calculate the value that the servo motor has to move
		int rotateValue = distance * 50;

		pwmWrite(GetPin(), 50);
		delay(1000);
		pwmWrite(GetPin(), 150);
		delay(1000);
		pwmWrite(GetPin(), 250);
		delay(1000);
	}
}