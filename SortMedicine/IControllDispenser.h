#pragma once
namespace Sorting {
	class IControllDispenser {
	public:
		/*
		Implement all method on start of the program
		*/
		virtual void Setup() = 0;

		/*
		Move servo motor the distance
		*/
		virtual void Update(int distance) = 0;

		/*
		Gets current position of the motor 
		*/
		inline int GetCurrentDegrees() { return m_currentDegrees; }
	protected:
		int m_currentDegrees;
	};
}