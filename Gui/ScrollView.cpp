#include "ScrollView.h"

#include <iostream>

namespace Gui {
	ScrollView::~ScrollView()
	{
		for (int i = 0; i < m_Blocks.size(); i++)
			delete m_Blocks[i];
	}

	void ScrollView::Add(Gui* block)
	{
		const Vector2 nextPos = GetPositionForNextItem();

		block->SetPos(nextPos);
		block->SetSize(GetSize().x - m_Style.scrollBarSize.x, m_Style.minHeight);

		m_Blocks.push_back(block);
	}

	void ScrollView::Update()
	{
		const Vector2 mPos = GetMousePosition();
		const Vector2& scrollPos = m_ScrollBarPosition;
		const Vector2& scrollSize = m_Style.scrollBarSize;
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		int deltaY = mPos.y - m_LastMousePos.y;
		m_LastMousePos = mPos;

		if (!CheckCollisionPointRec(mPos, { scrollPos.x, scrollPos.y, scrollSize.x, scrollSize.y }))
			return;

		if (deltaY > 50 || deltaY < -50)
			return;

		if (deltaY + scrollPos.y < pos.y || deltaY + scrollPos.y + scrollSize.y > pos.y + size.y)
			return;

		m_ScrollBarPosition.y += deltaY;

		for (int i = 0; i < m_Blocks.size(); i++)
			m_Blocks[i]->Translate(0, -deltaY);

	}

	void ScrollView::Draw()
	{
		// Draw list background
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		DrawRectangle(pos.x, pos.y, size.x, size.y, m_Style.backgrondColor);

		BeginScissorMode((int)pos.x, (int)pos.y, (int)size.x, (int)size.y);

		// Draw children
		for (int i = 0; i < m_Blocks.size(); i++)
			m_Blocks[i]->Draw();

		// Draw scrollbar
		DrawRectangle(m_ScrollBarPosition.x, m_ScrollBarPosition.y, m_Style.scrollBarSize.x, m_Style.scrollBarSize.y, m_Style.scrollBarColor);


		EndScissorMode();
	}

	int ScrollView::GetMaxItems()
	{
		return (int)(GetSize().y / m_Style.minHeight);
	}
	const Vector2 ScrollView::GetPositionForNextItem()
	{
		if (m_Blocks.size() == 0)
			return GetPos();

		int index = m_Blocks.size() - 1;

		const Vector2& lastPos = m_Blocks[index]->GetPos();

		return { lastPos.x, (lastPos.y + m_Style.minHeight) + m_Style.yMargin };
	}
}