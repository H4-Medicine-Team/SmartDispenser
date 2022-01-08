#pragma once
#include "Gui.h"
#include <string>
#include <Raylib.h>

namespace Gui {
	struct TextStyle {
		int fontSize = 14;
		Color color = BLACK;
	};

	class Text : public Gui
	{
	public:
		Text(const std::string& text, const Vector2& pos);
		~Text();

	public:
		virtual void Update() override;
		virtual void Draw() override;

		void SetDefaultStyle(const TextStyle& style) { m_DefaultStyle = style; }
		void SetHoverStyle(const TextStyle& style) { m_HoverStyle = style; }
		const TextStyle& GetDefaultStyle() { return m_DefaultStyle; }
		const TextStyle& GetHoverStyle() { return m_HoverStyle; }

		void SetText(const std::string& text);
		const std::string& GetText() { return m_Text; }

	private:
		const Vector2 GetTextSize();

	private:
		std::string m_Text;
		TextStyle m_DefaultStyle;
		TextStyle m_HoverStyle;
		TextStyle* m_CurrentStyle;
	};
}