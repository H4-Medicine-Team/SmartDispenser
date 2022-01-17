#pragma once
namespace Sorting {
	class IControllDispenser {
	public:
		virtual void Setup() = 0;
		virtual void Update(int toDegrees) = 0;
		inline int GetCurrentDegrees() { return m_currentDegrees; }
	protected:
		int m_currentDegrees;
	};
}