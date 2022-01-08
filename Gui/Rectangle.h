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
		void SetClickHandler(const std::function<void(Rectangle* object, const Vector2& mousePos, bool isPressed)>& callback);

		void SetDefaultStyle(const RectangleStyle& style) { m_DefaultStyle = style; }
		void SetHoverStyle(const RectangleStyle& style) { m_HoverStyle = style; }
		const RectangleStyle& GetDefaultStyle() { return m_DefaultStyle; }
		const RectangleStyle& GetHoverStyle() { return m_HoverStyle; }

		virtual void Update() override;
		virtual void Draw() override;

	private:
		bool IsCollidingWithTouch(const Vector2& mouse, const Vector2& pos, const Vector2& size);

	private:
		RectangleStyle* m_CurrentStyle;
		RectangleStyle m_DefaultStyle;
		RectangleStyle m_HoverStyle;

		std::function<void(Rectangle* object, const Vector2& mousePos, bool isPressed)> m_ClickCallBack;

		bool m_LastClicked;
	};
}


