#include "EditButton.h"

namespace Gui {
	EditButton::EditButton(const std::string& constText, const std::string& editableText, const Vector2& pos, const Vector2& size)
		: m_Rectangle(pos, size),
		m_ConstText(constText, pos),
		m_EditableText(editableText, pos),
		m_ClickCallback(),
		Gui::Gui(pos, size)
	{
		m_Rectangle.SetClickHandler(std::bind(&EditButton::RectangleOnClick, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		SetupChildren();
	}

	EditButton::~EditButton()
	{
	}

	void EditButton::Update()
	{
		m_Rectangle.Update();
		m_ConstText.Update();
		m_EditableText.Update();
	}

	void EditButton::Draw()
	{
		m_Rectangle.Draw();
		m_ConstText.Draw();
		m_EditableText.Draw();
	}

	void EditButton::SetPos(const Vector2& pos)
	{
		Gui::SetPos(pos);

		SetupChildren();
	}

	void EditButton::SetPos(float x, float y)
	{
		SetPos({ x, y });
	}

	void EditButton::SetSize(const Vector2& size)
	{
		Gui::SetSize(size);

		SetupChildren();
	}

	void EditButton::SetSize(float w, float h)
	{
		SetSize({ w, h });
	}

	void EditButton::SetDefaultStyle(const TextStyle& textStyle, const RectangleStyle& rectStyle)
	{
		m_Rectangle.SetDefaultStyle(rectStyle);

		m_ConstText.SetDefaultStyle(textStyle);
		m_EditableText.SetDefaultStyle(textStyle);

		SetupChildren();
	}

	void EditButton::SetHoverStyle(const TextStyle& textStyle, const RectangleStyle& rectStyle)
	{
		m_Rectangle.SetHoverStyle(rectStyle);

		m_ConstText.SetHoverStyle(textStyle);
		m_EditableText.SetHoverStyle(textStyle);

		SetupChildren();
	}

	void EditButton::SetText(const std::string& text)
	{
		m_EditableText.SetText(text);
		SetupChildren();
	}

	void EditButton::SetClickHandler(const std::function<void(EditButton* btn, const Vector2& mousePos, bool isPressed)>& clickHandler)
	{
		m_ClickCallback = clickHandler;
	}

	const std::string& EditButton::GetText()
	{
		return m_EditableText.GetText();
	}

	void EditButton::RectangleOnClick(Rectangle* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!m_ClickCallback)
			return;

		m_ClickCallback(this, mousePos, isPressed);
	}

	void EditButton::SetupChildren()
	{
		m_Rectangle.SetPos(GetPos());
		m_Rectangle.SetSize(GetSize());

		Vector2 constPos = GetPos();
		constPos.y += (GetSize().y / 2) - (m_ConstText.GetSize().y / 2);
		constPos.x += 5;
		m_ConstText.SetPos(constPos);

		Vector2 editPos = GetPos();
		editPos.x += (GetSize().x - m_EditableText.GetSize().x - 5);
		editPos.y += (GetSize().y / 2) - (m_EditableText.GetSize().y / 2);
		m_EditableText.SetPos(editPos);
	}
}