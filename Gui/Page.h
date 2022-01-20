#pragma once
#include "Gui.h"
#include <Raylib.h>
#include <vector>
#include "Keyboard.h"

namespace Gui {
	class Page
	{
	public:
		Page();
		~Page();

	protected:
		/*
		* Adds a gui element to the page
		*/
		void Add(Gui* guiBlock);

		/*
		* Set background color
		*/
		inline void SetBackgroundColor(const Color& color) { m_BackgroundColor = color; }

		/*
		* Get background color
		*/
		inline const Color& GetBackgroundColor() { return m_BackgroundColor; }

		/*
		* Retrieve the current keyboard located in the page
		*/
		inline Keyboard& GetKeyboard() { return m_Keyboard; }

		/*
		* Clear all the gui elements from the page
		*/
		inline void Clear() {
			for (int i = 0; i < m_GuiBlocks.size(); i++)
				delete m_GuiBlocks[i];

			m_GuiBlocks.clear();
		}

	private:
		/*
		* This method is called each frame, and updates all the gui blocks in the page
		*/
		void Update();

		/*
		* This method is called for each frame, and draws all the gui blocks in the page
		*/
		void Draw();
		friend class PageHandler;
	private:
		std::vector<Gui*> m_GuiBlocks;
		Color m_BackgroundColor = WHITE;
		Keyboard m_Keyboard;

	};
}