#pragma once
#include <Raylib.h>
#include "Gui.h"
#include <string>

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
		const std::string& GetText() { return m_Text; }
		const ButtonStyle& GetStyle() { return m_Style; }

		void SetText(const char* text) { m_Text = text; }
		void SetStyle(const ButtonStyle& style) { m_Style = style; }
		void SetClickCallback(void (*callback)(Button* button, bool isPressed));

	public:
		void Update() override;
		void Draw() override;

	private:
		void DrawBox();
		void DrawString();
		bool CheckForClick();

	private:
		std::string m_Text;
		void (*m_ClickCallback)(Button* button, bool isPressed);

		ButtonStyle m_Style;

		bool m_LastClicked;
	};
}