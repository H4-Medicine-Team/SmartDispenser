#include "Button.h"
#include "Raylib.h"

namespace Gui {
	void Button::Update()
	{
		if (!m_ClickCallback)
			return;

		bool currentlyClicked = CheckForClick();

		if (currentlyClicked != m_LastClicked)
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
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		DrawRectangle(pos.x, pos.y, size.x, size.y, m_Style.backgroundColor);
	}

	void Button::DrawString()
	{
		const Vector2& center = GetCenter();
		const Vector2 textHalfSize = { MeasureText(m_Text.c_str(), m_Style.textSize) / 2, m_Style.textSize / 2 };
		DrawText(m_Text.c_str(), center.x - textHalfSize.x, center.y - textHalfSize.y, m_Style.textSize, m_Style.textColor);
	}

	bool Button::CheckForClick()
	{
		Vector2 touchPos = GetTouchPosition(0);
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		if (CheckCollisionPointRec(touchPos, { pos.x, pos.y, size.x, size.y}))
			return true;

		return false;
	}

}