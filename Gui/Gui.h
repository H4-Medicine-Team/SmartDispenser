#pragma once
#include <Raylib.h>

namespace Gui {
	class Gui {
	public:
		Gui(const Vector2& position) 
			: m_IsVisible(true), 
			m_Pos(position) {};

		const Vector2& GetPos() { return m_Pos; }

		void SetPos(const Vector2& pos) { m_Pos = pos; }
		void SetPos(float x, float y) { m_Pos = { x, y }; }

	protected:
		virtual void Update() = 0;
		virtual void Draw() = 0;
	
	private:
		bool m_IsVisible;
		Vector2 m_Pos;

		friend class Page;
	};
}