#include "ScrollBar.h"

namespace Gui {
	ScrollBar::ScrollBar(const Vector2& position, const Vector2& size, const ScrollBarStyle& style)
		: Gui(position, size),
		m_Style(style)
	{}

	ScrollBar::~ScrollBar()
	{
	}

	void ScrollBar::Update()
	{
	}

	void ScrollBar::Draw()
	{
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		DrawRectangle(pos.x, pos.y, size.x, size.y, m_Style.scrollBarColor);
	}
}

