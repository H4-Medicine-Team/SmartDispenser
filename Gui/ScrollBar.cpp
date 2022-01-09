#include "ScrollBar.h"
#include "../Application/Input.h"

namespace Gui {
	ScrollBar::ScrollBar(const Vector2& position, const Vector2& size, const Vector2& barSize, const Vector2& scrollBarPosition)
		: Gui(position, size),
		m_Style({}),
		m_ScrollBarSize(barSize),
		m_ScrollBarPosition(scrollBarPosition)
	{}

	ScrollBar::~ScrollBar()
	{
	}

	void ScrollBar::Update()
	{
		const Vector2& mousePos = Application::Input::Get().GetTPosition();
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		if (!IsMouseColliding(mousePos, pos, size))
			return;

		UpdateScrollBarPosition(mousePos, pos, size);

		if (m_ScrollBarCallback)
			m_ScrollBarCallback(GetCurrentScrolledPercent());
	}

	void ScrollBar::UpdateScrollBarPosition(const Vector2& mPos, const Vector2& pos, const Vector2& size)
	{
			if (mPos.y < pos.y + size.y - m_ScrollBarSize.y)
				m_ScrollBarPosition.y = mPos.y;
	}

	bool ScrollBar::IsMouseColliding(const Vector2& mPos, const Vector2& pos, const Vector2& size)
	{
		return CheckCollisionPointRec(mPos, { pos.x, pos.y, size.x, size.y });
	}

	float ScrollBar::GetCurrentScrolledPercent()
	{
		float fullHeight = GetSize().y - m_ScrollBarSize.y;
		float currentHeight = m_ScrollBarPosition.y - GetPos().y;

		return currentHeight / fullHeight;
	}

	void ScrollBar::Draw()
	{
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		// Draw background
		DrawRectangle(pos.x, pos.y, size.x, size.y, m_Style.scrollBarBackgroundColor);

		// Draw bar
		DrawRectangle(m_ScrollBarPosition.x, m_ScrollBarPosition.y, m_ScrollBarSize.x, m_ScrollBarSize.y, m_Style.scrollBarColor);
	}

	void ScrollBar::SetScrollCallback(const std::function<void(float percentage)>& scrollCallback)
	{
		m_ScrollBarCallback = scrollCallback;
	}
	
}

