#include "Rectangle.h"
#include "../Application/Input.h"

namespace Gui {
	
	Rectangle::Rectangle(const Vector2& pos, const Vector2& size) 
		: Gui(pos, size),
		m_HoverStyle(),
		m_DefaultStyle(),
		m_CurrentStyle(&m_DefaultStyle),
		m_ClickCallBack(0),
		m_LastClicked(false) {}

	Rectangle::~Rectangle()
	{}

	void Rectangle::SetClickHandler(const std::function<void(Rectangle* object, const Vector2& mousePos, bool isPressed)>& callback)
	{
		m_ClickCallBack = callback;
	}

	void Rectangle::Update()
	{
		m_CurrentStyle = &m_DefaultStyle;

		if (!m_ClickCallBack)
			return;

		const Vector2& touchPos = Application::Input::Get().GetTPosition();
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		bool currentlyClicked = IsCollidingWithTouch(touchPos, pos, size);

		if (currentlyClicked != m_LastClicked)
		{
			m_CurrentStyle = &m_HoverStyle;
			m_ClickCallBack(this, touchPos, currentlyClicked);
		}

		m_LastClicked = currentlyClicked;
	}

	void Rectangle::Draw()
	{
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		DrawRectangleRounded({ pos.x - m_CurrentStyle->borderSize, pos.y - m_CurrentStyle->borderSize, size.x + m_CurrentStyle->borderSize * 2, size.y + m_CurrentStyle->borderSize * 2 }, m_CurrentStyle->rounding, m_CurrentStyle->segments, m_CurrentStyle->borderColor);
		DrawRectangleRounded({ pos.x, pos.y, size.x, size.y }, m_CurrentStyle->rounding, m_CurrentStyle->segments, m_CurrentStyle->backgroundColor);
	}

	bool Rectangle::IsCollidingWithTouch(const Vector2& mouse, const Vector2& pos, const Vector2& size)
	{
		return CheckCollisionPointRec(mouse, { pos.x, pos.y, size.x, size.y });
	}
}