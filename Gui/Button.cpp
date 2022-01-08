#include "Button.h"
#include "Raylib.h"
#include "../Application/Input.h"

#include <functional>

namespace Gui {

	Button::Button(const std::string& text, const Vector2& position, const Vector2& size) 
	:	m_Rectangle(position, size),
		m_Text(text, position),
		m_ClickCallback(0),
		Gui::Gui(position, size)
	{
		TextStyle tStyle{};
		tStyle.color = WHITE;

		m_Text.SetDefaultStyle(tStyle);
		SetChildrenPos();
		m_Rectangle.SetClickHandler(std::bind(&Button::RectangleOnClick, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	}

	Button::~Button()
	{
	}

	void Button::SetPos(float x, float y)
	{
		Gui::SetPos(x, y);

		SetChildrenPos();
	}

	void Button::SetPos(const Vector2& pos)
	{
		SetPos(pos.x, pos.y);
	}

	void Button::SetSize(float x, float y)
	{
		Gui::SetSize(x, y);
		m_Rectangle.SetSize(x, y);

		SetChildrenPos();
	}

	void Button::SetSize(const Vector2& size)
	{
		SetSize(size.x, size.y);
	}

	void Button::SetClickHandler(const std::function<void(Button* btn, const Vector2& mousePos, bool isPressed)>& clickHandler)
	{
		m_ClickCallback = clickHandler;
	}

	void Button::Update()
	{
		m_Rectangle.Update();
		m_Text.Update();
	}

	void Button::Draw()
	{
		m_Rectangle.Draw();
		m_Text.Draw();

	}
	void Button::SetChildrenPos()
	{
		const Vector2& pos = GetPos();

		m_Rectangle.SetPos(pos.x, pos.y);

		const Vector2& center = m_Rectangle.GetCenter();
		const Vector2& textSize = m_Text.GetSize();

		m_Text.SetPos({ center.x - (textSize.x / 2), center.y - (textSize.y / 2) });
	}

	void Button::RectangleOnClick(Rectangle* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!m_ClickCallback)
			return;

		m_ClickCallback(this, mousePos, isPressed);
	}
}