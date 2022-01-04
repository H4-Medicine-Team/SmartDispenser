#pragma once
#include "Gui.h"
#include <vector>

namespace Gui {
	class Page
	{
	public:
		Page();
		~Page();
	protected:
		void Add(Gui* guiBlock);
	private:
		void Update();
		void Draw();
		friend class PageHandler;
	private:
		std::vector<Gui*> m_GuiBlocks;

	};
}