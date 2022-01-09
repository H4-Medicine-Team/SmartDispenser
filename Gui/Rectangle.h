#pragma once
#include "Gui.h"
#include <Raylib.h>
#include <functional>

namespace Gui {
	struct RectangleStyle {
		Color backgroundColor {180, 0, 0, 255};
		Color borderColor {0, 0, 0, 255};
		int borderSize = 1;
		float rounding = 0.2f;
		int segments = 50;
	};

	class Rectangle : public Gui
	{
	public:
		Rectangle(const Vector2& pos, const Vector2& size);
		~Rectangle();

	public:
		/*
		* Set the current click handler for the rectangle
		*/
		void SetClickHandler(const std::function<void(Rectangle* object, const Vector2& mousePos, bool isPressed)>& callback);

		/*
		* Set the current default style for the rectangle
		*/
		void SetDefaultStyle(const RectangleStyle& style) { m_DefaultStyle = style; }

		/*
		* Set the current hover style for the rectangle
		*/
		void SetHoverStyle(const RectangleStyle& style) { m_HoverStyle = style; }

		/*
		* Get the current default style for the rectangle
		*/
		const RectangleStyle& GetDefaultStyle() { return m_DefaultStyle; }

		/*
		* Get the current hover style for the rectangle
		*/
		const RectangleStyle& GetHoverStyle() { return m_HoverStyle; }

		virtual void Update() override;
		virtual void Draw() override;

	private:
		/*
		* Checks whether the current rectangle is colliding with the mouse positon given.
		*/
		bool IsCollidingWithTouch(const Vector2& mouse, const Vector2& pos, const Vector2& size);

	private:
		RectangleStyle* m_CurrentStyle;
		RectangleStyle m_DefaultStyle;
		RectangleStyle m_HoverStyle;

		std::function<void(Rectangle* object, const Vector2& mousePos, bool isPressed)> m_ClickCallBack;

		bool m_LastClicked;
	};
}


