#pragma once
#include "Gui.h"
#include <Raylib.h>
#include <vector>
#include "ScrollBar.h"

namespace Gui {
	struct ScrollViewStyle {
		Color backgrondColor = WHITE;
		int minHeight = 50;
		int yMargin = 2;
		int xMargin = 2;
		ScrollBarStyle barStyle{};
	};

	class ScrollView : public Gui
	{
	public:
		ScrollView(const Vector2& position, const Vector2& size, const Vector2& barSize);
		~ScrollView();
	public:
		/*
		* Adds a gui element to the list in the scroll view
		*/
		void Add(Gui* block);
		
		/*
		* Get the index for the element given
		* if no element exists returns -1
		*/
		int GetElementIndex(Gui* block);

	protected:
		void Update() override;
		void Draw() override;

	private:
		/*
		* returns the position for the next item
		*/
		const Vector2 GetPositionForNextItem();

		/*
		* Gets the default position for a element based upon it's position in the list
		*/
		const Vector2 GetDefaultPositionForItem(int index, const Vector2& startPos);

		/*
		* Called when the scroll bar has changed position
		*/
		void OnScrollBarPositionChanged(float percent);

		/*
		* Gets the full length of the childrens in the scrollview
		*/
		const float GetChildrenHeight();

	private:
		ScrollViewStyle m_Style;
		std::vector<Gui*> m_Blocks;
		ScrollBar m_ScrollBar;
	};
}

