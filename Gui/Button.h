#pragma once
#include "Gui.h"
#include "Rectangle.h"
#include "Text.h"

namespace Gui {

	struct ButtonStyle {
		TextStyle textStyle{};
		RectangleStyle rectangleStyle{};
	};

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

		/*
		* Set the buttons text
		*/
		void SetText(const std::string& text);

		/*
		* Get the text of the button
		*/
		const std::string& GetText();

		/*
		* Set Default style for the button
		*/
		void SetDefaultStyle(const ButtonStyle& style);

		/*
		* Set hover style for button
		*/
		void SetHoverStyle(const ButtonStyle& style);

		/*
		* Get default style from the button
		*/
		ButtonStyle GetDefaultStyle() { ButtonStyle s{}; s.textStyle = m_Text.GetDefaultStyle(); s.rectangleStyle = m_Rectangle.GetDefaultStyle(); return s;}
		
		/*
		* Get hover style from button
		*/
		ButtonStyle GetHoverStyle() { ButtonStyle s{}; s.textStyle = m_Text.GetHoverStyle(); s.rectangleStyle = m_Rectangle.GetHoverStyle(); return s; }

		/*
		* Set the current handler for when the button is being clicked
		* btn -> The current button which was clicked
		* mousePos -> The current mouse position for when the button was clicked
		* isPressed -> Whether the button is down or up.
		*/
		void SetClickHandler(const std::function<void(Button* btn, const Vector2& mousePos, bool isPressed)>& clickHandler);

		void Update() override;
		void Draw() override;

	private:
		/*
		* Set the position for all the children in the button
		*/
		void SetChildrenPos();

		/*
		* Called when the rectangle is clicked
		* btn -> The current rectangle "button"
		* mousePos -> The current mouse position for when the button was clicked
		* isPressed -> Whether the click is up or down
		*/
		void RectangleOnClick(Rectangle* btn, const Vector2& mousePos, bool isPressed);

	private:
		Rectangle m_Rectangle;
		Text m_Text;

		std::function<void(Button* btn, const Vector2& mousePos, bool isPressed)> m_ClickCallback;
	};
}