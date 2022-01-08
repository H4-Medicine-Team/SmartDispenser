#include "ScrollView.h"

#include <iostream>
#include <functional>

namespace Gui {
	ScrollView::ScrollView(const Vector2& position, const Vector2& size, const Vector2& barSize)
		: m_Style({}),
		m_Blocks(0),
		m_ScrollBar(
			{position.x + size.x - barSize.x, position.y},
			{barSize.x, size.y},
			barSize,
			{position.x + size.x - barSize.x, position.y}
		),
		Gui(position, size) 
	{
		m_ScrollBar.SetScrollCallback(std::bind(&ScrollView::OnScrollBarPositionChanged, this, std::placeholders::_1));
		m_ScrollBar.SetIsVisible(false);
	}

	ScrollView::~ScrollView()
	{
		for (int i = 0; i < m_Blocks.size(); i++)
			delete m_Blocks[i];
	}

	void ScrollView::Add(Gui* block)
	{
		m_Blocks.push_back(block);

		const Vector2 nextPos = GetPositionForNextItem();

		block->SetPos(nextPos);
		block->SetSize(GetSize().x - m_ScrollBar.GetSize().x, m_Style.minHeight);

		bool shouldShowBar = GetChildrenHeight() > GetSize().y;
		m_ScrollBar.SetIsVisible(shouldShowBar);		
	}

	void ScrollView::Update()
	{
		if (m_ScrollBar.IsVisible())
			m_ScrollBar.Update();

		// Update children
		for (int i = 0; i < m_Blocks.size(); i++)
		{
			if (!m_Blocks[i]->IsVisible())
				continue;

			m_Blocks[i]->Update();
		}
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
		{
			if (!m_Blocks[i]->IsVisible())
				continue;

			m_Blocks[i]->Draw();
		}

		if (m_ScrollBar.IsVisible())
			m_ScrollBar.Draw();

		EndScissorMode();
	}

	const Vector2 ScrollView::GetPositionForNextItem()
	{
		int index = m_Blocks.size() - 1;

		return GetDefaultPositionForItem(index, GetPos());
	}

	const Vector2 ScrollView::GetDefaultPositionForItem(int index, const Vector2& startPos)
	{
		return {
			startPos.x,
			startPos.y + (index * m_Style.minHeight) + (m_Style.yMargin * index)
		};
	}

	void ScrollView::OnScrollBarPositionChanged(float percent)
	{
		const Vector2& startPos = GetPos();
		const Vector2& size = GetSize();

		int itemCount = m_Blocks.size();
		float fullListLength = GetChildrenHeight();
		const float translateY = (fullListLength - size.y) * percent;

		for (int i = 0; i < itemCount; i++)
		{
			const Vector2 defPos = GetDefaultPositionForItem(i, startPos);

			m_Blocks[i]->SetPos(defPos.x, defPos.y - translateY);
		}
	}

	const float ScrollView::GetChildrenHeight()
	{
		int itemCount = m_Blocks.size();
		return (itemCount * m_Style.minHeight) + (m_Style.yMargin * itemCount);
	}
}