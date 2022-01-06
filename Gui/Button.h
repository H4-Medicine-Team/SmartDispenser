#pragma once
#include <Raylib.h>
#include "Gui.h"
#include <string>
#include <functional>

namespace Gui {

	struct ButtonStyle {
		Color backgroundColor;
		Color textColor;
		int textSize;
	};

	class Button : public Gui
	{
	public:
		Button(const std::string& text, const Vector2& position, const Vector2& size, const ButtonStyle& style)
			: m_Text(text.c_str()),
			m_Style(style),
			m_LastClicked(false),
			m_ClickCallback(0),
			Gui::Gui(position, size) {}

	public:
		// Get the current for the button
		const std::string& GetText() { return m_Text; }

		// Get the buttons current style
		const ButtonStyle& GetStyle() { return m_Style; }

		// Set the current text
		void SetText(const char* text) { m_Text = text; }

		// Set the current style
		void SetStyle(const ButtonStyle& style) { m_Style = style; }

		// Set the current callback for when clicking the button
		void SetClickCallback(std::function<void(Button* button, bool isPressed)> clickCallback);

	protected:
		void Update() override;
		void Draw() override;

	private:
		// Draws the box / rectangle.
		void DrawBox();

		// Draws the text / string for the button
		void DrawString();

		// Checks whether the button has been clicked
		bool CheckForClick();

	private:
		std::string m_Text;
		std::function<void(Button* button, bool isPressed)> m_ClickCallback;

		ButtonStyle m_Style;

		bool m_LastClicked;
	};
}