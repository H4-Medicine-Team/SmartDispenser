#pragma once

#include <Raylib.h>
#include "Gui.h"
#include <functional>

namespace Gui {
	struct ScrollBarStyle {
		Color scrollBarBackgroundColor;
		Color scrollBarColor;
	};

	class ScrollBar : public Gui
	{
	public:
		ScrollBar(const Vector2& position, const Vector2& size, const Vector2& barSize, const Vector2& scrollBarPosition, const ScrollBarStyle& style);
		~ScrollBar();

	public:
		// Sets the callback for the scrollbar when the position has been changed, the input parameter is the scroll bars progress in percentage
		void SetScrollCallback(const std::function<void(float percentage)>& scrollCallback);

	protected:
		// Updates the gui elements
		virtual void Update() override;

		// Draws all the gui elements
		virtual void Draw() override;

		friend class ScrollView;

	private:
		// Updates the scroll bars position
		void UpdateScrollBarPosition(const Vector2& mPos, const Vector2& pos, const Vector2& size);

		// Returns whether the mouse is colliding with scrollbar
		bool IsMouseColliding(const Vector2& mPos, const Vector2& pos, const Vector2& size);

		// Gets the current scrolled percentage
		float GetCurrentScrolledPercent();

	private:
		ScrollBarStyle m_Style;
		Vector2 m_ScrollBarSize;
		Vector2 m_ScrollBarPosition;
		std::function<void(float percent)> m_ScrollBarCallback;
	};
}


