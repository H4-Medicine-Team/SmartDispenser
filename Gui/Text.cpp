#include "Text.h"

namespace Gui {
	Text::Text(const std::string& text, const Vector2& pos)
		: m_Text(text),
		m_DefaultStyle({}),
		m_HoverStyle({}),
		m_CurrentStyle(&m_DefaultStyle),
		Gui::Gui(pos, {}) 
	{
		SetSize(GetTextSize());
	}

	Text::~Text()
	{
	}

	void Text::SetText(const std::string& text)
	{
		m_Text = text;
		SetSize(GetTextSize());
	}

	const Vector2 Text::GetTextSize()
	{
		return { (float)MeasureText(m_Text.c_str(), (float)m_CurrentStyle->fontSize), (float)m_CurrentStyle->fontSize };
	}

	void Text::Update()
	{
	}

	void Text::Draw()
	{
		const Vector2& pos = GetPos();

		DrawText(m_Text.c_str(), pos.x, pos.y, m_CurrentStyle->fontSize, m_CurrentStyle->color);
	}
}