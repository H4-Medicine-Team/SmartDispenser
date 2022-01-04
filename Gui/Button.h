#pragma once
#include <Raylib.h>
#include "Gui.h"

namespace Gui {

	struct ButtonStyle {
		Color backgroundColor;
		Color textColor;
		int textSize;
	};

	class Button : public Gui
	{
	public:
		Button(const char* text, const Vector2& position, const Vector2& size, const ButtonStyle& style)
			: m_Text(text),
			m_Size(size),
			m_Style(style),
			m_LastClicked(false),
			m_ClickCallback(0),
			Gui::Gui(position) {}

	public:
		const Vector2& GetSize() { return m_Size; }
		const char* GetText() { return m_Text; }
		const ButtonStyle& GetStyle() { return m_Style; }

		void SetSize(float w, float h) { m_Size = { w, h }; }
		void SetText(const char* text) { m_Text = text; }
		void SetStyle(const ButtonStyle& style) { m_Style = style; }
		void SetClickCallback(void (*callback)(Button* button, bool isPressed));

	protected:
		void Update() override;
		void Draw() override;

	private:
		void DrawBox();
		void DrawString();
		bool CheckForClick();

	private:
		const char* m_Text;
		Vector2 m_Size;
		void (*m_ClickCallback)(Button* button, bool isPressed);

		ButtonStyle m_Style;

		bool m_LastClicked;
	};
}