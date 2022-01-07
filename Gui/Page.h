#pragma once
#include "Gui.h"
#include <Raylib.h>
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

		// Set background color
		inline void SetBackgroundColor(Color color) { m_BackgroundColor = color; }

		// Get background color
		inline const Color& GetBackgroundColor() { return m_BackgroundColor; }
	private:
		// This method is called each frame, and updates all the gui blocks in the page
		void Update();

		// This method is called for each frame, and draws all the gui blocks in the page
		void Draw();
		friend class PageHandler;
	private:
		std::vector<Gui*> m_GuiBlocks;
		Color m_BackgroundColor = WHITE;

	};
}