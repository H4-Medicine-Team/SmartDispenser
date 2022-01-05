#pragma once
#include "Gui.h"
#include <Raylib.h>
#include <vector>
#include "Button.h"

namespace Gui {
	struct ScrollViewStyle {
		Color backgrondColor;
		int minHeight;
		int yMargin;
		Vector2 scrollBarSize;
		Color scrollBarColor;
	};

	class ScrollView : public Gui
	{
	public:
		ScrollView(const Vector2& position, const Vector2& size, const ScrollViewStyle& style)
			: m_Style(style),
			m_Blocks(0),
			m_ScrollBarPosition({position.x + size.x - style.scrollBarSize.x, position.y}),
			m_LastMousePos(),
			Gui(position, size) {}

		~ScrollView();
	public:
		void Add(Gui* block);

	protected:
		void Update() override;
		void Draw() override;

	private:
		int GetMaxItems();
		const Vector2 GetPositionForNextItem();

	private:
		ScrollViewStyle m_Style;
		std::vector<Gui*> m_Blocks;
		Vector2 m_ScrollBarPosition;
		Vector2 m_LastMousePos;
	};
}

