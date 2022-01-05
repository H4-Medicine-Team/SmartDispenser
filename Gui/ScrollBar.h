#pragma once

#include <Raylib.h>
#include "Gui.h"

namespace Gui {
	struct ScrollBarStyle {
		Color scrollBarColor;
	};

	class ScrollBar : public Gui
	{
	public:
		ScrollBar(const Vector2& position, const Vector2& size, const ScrollBarStyle& style);
		~ScrollBar();
		virtual void Update() override;
		virtual void Draw() override;

	private:
		ScrollBarStyle m_Style;

	};
}


