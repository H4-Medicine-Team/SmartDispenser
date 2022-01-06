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
		// Adds a gui element to the page
		void Add(Gui* guiBlock);

		// This method is called when the page is being set
		virtual void Start() = 0;

		// is called when another page is being set as the current, and this one has been the current
		virtual void Unload();
	private:
		// This method is called each frame, and updates all the gui blocks in the page
		void Update();

		// This method is called for each frame, and draws all the gui blocks in the page
		void Draw();
		friend class PageHandler;
	private:
		std::vector<Gui*> m_GuiBlocks;

	};
}