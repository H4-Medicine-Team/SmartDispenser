#include "Input.h"


namespace Application {

	void Input::Update()
	{
		m_DeltaTime = GetFrameTime();
		m_MousePosition = GetMousePosition();
		m_TouchPosition = GetTouchPosition(0);
	}
}