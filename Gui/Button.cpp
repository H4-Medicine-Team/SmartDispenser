#include "Button.h"
#include "Raylib.h"

namespace Gui {
	void Button::Update()
	{
		bool currentlyClicked = CheckForClick();

		if (currentlyClicked != m_LastClicked)
			if (m_ClickCallback)
				m_ClickCallback(this, currentlyClicked);

		m_LastClicked = currentlyClicked;
	}

	void Button::Draw()
	{
		DrawBox();
		DrawString();
	}

	void Button::SetClickCallback(void(*callback)(Button* button, bool ispressed))
	{
		m_ClickCallback = callback;
	}

	void Button::DrawBox()
	{
		const Vector2& center = GetPos();

		const Vector2 rectHalfSize = { m_Size.x / 2, m_Size.y / 2 };
		DrawRectangle(center.x - rectHalfSize.x, center.y - rectHalfSize.y, m_Size.x, m_Size.y, m_Style.backgroundColor);
	}

	void Button::DrawString()
	{
		const Vector2& center = GetPos();
		const Vector2 textHalfSize = { MeasureText(m_Text, m_Style.textSize) / 2, m_Style.textSize / 2 };
		DrawText(m_Text, center.x - textHalfSize.x, center.y - textHalfSize.y, m_Style.textSize, m_Style.textColor);
	}

	bool Button::CheckForClick()
	{
		Vector2 touchPos = GetTouchPosition(0);
		const Vector2& center = GetPos();

		if (CheckCollisionPointRec(touchPos, { center.x - (m_Size.x / 2), center.y - (m_Size.y / 2), m_Size.x, m_Size.y}))
			return true;

		return false;
	}

}