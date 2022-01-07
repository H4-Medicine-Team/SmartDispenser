#pragma once
#include "Gui.h"
#include "Rectangle.h"
#include "Text.h"

namespace Gui {

	class Button : public Gui
	{
	public:
		Button(const std::string& text, const Vector2& position, const Vector2& size);
		~Button();
	public:
		void SetPos(float x, float y) override;
		void SetPos(const Vector2& pos) override;

		void SetSize(float x, float y) override;
		void SetSize(const Vector2& size) override;

		void SetClickHandler(const std::function<void(Button* btn, const Vector2& mousePos, bool isPressed)>& clickHandler);

	protected:
		void Update() override;
		void Draw() override;

	private:
		void SetChildrenPos();

		void RectangleOnClick(Rectangle* btn, const Vector2& mousePos, bool isPressed);

	private:
		Rectangle m_Rectangle;
		Text m_Text;

		std::function<void(Button* btn, const Vector2& mousePos, bool isPressed)> m_ClickCallback;
	};
}