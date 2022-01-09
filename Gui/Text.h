#pragma once
#include "Gui.h"
#include <string>
#include <Raylib.h>

namespace Gui {
	struct TextStyle {
		int fontSize = 14;
		Color color = WHITE;
	};

	class Text : public Gui
	{
	public:
		Text(const std::string& text, const Vector2& pos);
		~Text();

	public:
		virtual void Update() override;
		virtual void Draw() override;

		/*
		* Set the current default style for the text
		*/
		void SetDefaultStyle(const TextStyle& style) { m_DefaultStyle = style; SetSize(GetTextSize());}

		/*
		* Set the current hover style for the current text
		*/
		void SetHoverStyle(const TextStyle& style) { m_HoverStyle = style; SetSize(GetTextSize());}

		/*
		* Get the current default style for the text
		*/
		const TextStyle& GetDefaultStyle() { return m_DefaultStyle; }

		/*
		* Get the current hover style for the text
		*/
		const TextStyle& GetHoverStyle() { return m_HoverStyle; }

		/*
		* Set the crrent text for the text element
		*/
		void SetText(const std::string& text);

		/*
		* Get the current text from the element
		*/
		const std::string& GetText() { return m_Text; }

	private:
		/*
		* Returns the text size
		*/
		const Vector2 GetTextSize();

	private:
		std::string m_Text;
		TextStyle m_DefaultStyle;
		TextStyle m_HoverStyle;
		TextStyle* m_CurrentStyle;
	};
}