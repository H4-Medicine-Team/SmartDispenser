#pragma once
#include "Gui.h"
#include <Raylib.h>
#include <vector>
#include "ScrollBar.h"

namespace Gui {
	struct ScrollViewStyle {
		Color backgrondColor;
		int minHeight;
		int yMargin;
		ScrollBarStyle barStyle;
	};

	class ScrollView : public Gui
	{
	public:
		ScrollView(const Vector2& position, const Vector2& size, const Vector2& barSize, const ScrollViewStyle& style);
		~ScrollView();
	public:
		// Adds a gui element to the list in the scroll view
		void Add(Gui* block);

	protected:
		// Updates the current scrollview and all its children
		void Update() override;

		// Draws the current scrollview and all its children
		void Draw() override;

	private:
		// returns the position for the next item
		const Vector2 GetPositionForNextItem();

		// Gets the default position for a element based upon it's position in the list
		const Vector2 GetDefaultPositionForItem(int index, const Vector2& startPos);

		// Called when the scroll bar has changed position
		void OnScrollBarPositionChanged(float percent);

		// Gets the full length of the childrens in the scrollview
		const float GetChildrenHeight();

	private:
		ScrollViewStyle m_Style;
		std::vector<Gui*> m_Blocks;
		ScrollBar m_ScrollBar;
	};
}

