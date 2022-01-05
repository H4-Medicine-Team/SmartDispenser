#include "Page.h"
#include "Raylib.h"

namespace Gui {
	Page::Page() : m_GuiBlocks(0) {}

	Page::~Page()
	{
		for (int i = 0; i < m_GuiBlocks.size(); i++)
			delete m_GuiBlocks[i];
	}

	void Page::Add(Gui* guiBlock)
	{
		m_GuiBlocks.push_back(guiBlock);
	}

	void Page::Unload()
	{
		for (int i = 0; i < m_GuiBlocks.size(); i++)
			delete m_GuiBlocks[i];

		m_GuiBlocks.resize(0);
	}

	void Page::Update()
	{
		for (int i = 0; i < m_GuiBlocks.size(); i++)
		{
			if (!m_GuiBlocks[i]->m_IsVisible)
				continue;

			m_GuiBlocks[i]->Update();
		}
	}

	void Page::Draw()
	{
		for (int i = 0; i < m_GuiBlocks.size(); i++)
		{
			if (!m_GuiBlocks[i]->m_IsVisible)
				continue;

			m_GuiBlocks[i]->Draw();
		}
	}
}
