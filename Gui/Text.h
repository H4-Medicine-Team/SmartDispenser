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

	private:
		const Vector2 GetTextSize();

	private:
		std::string m_Text;
		TextStyle m_DefaultStyle;
		TextStyle m_HoverStyle;
		TextStyle* m_CurrentStyle;
	};
}