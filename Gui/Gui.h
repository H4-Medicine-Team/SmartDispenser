#pragma once
#include <Raylib.h>

namespace Gui {
	class Gui {
	public:
		Gui(const Vector2& position, const Vector2& size) 
			: m_IsVisible(true), 
			m_Pos(position),
			m_Size(size) {};

		const Vector2& GetPos() { return m_Pos; }
		const Vector2& GetSize() { return m_Size; }
		const Vector2 GetCenter() { return { m_Pos.x + (m_Size.x / 2), m_Pos.y + (m_Size.y / 2) }; }

		void SetPos(const Vector2& pos) { m_Pos = pos; }
		void SetPos(float x, float y) { m_Pos = { x, y }; }
		void SetSize(const Vector2& pos) { m_Size = pos; }
		void SetSize(float w, float h) { m_Size = { w, h }; }
		void Translate(const Vector2& pos) { m_Pos.x += pos.x; m_Pos.y += pos.y; }
		void Translate(float x, float y) { m_Pos.x += x; m_Pos.y += y; }

	public:
		virtual void Update() = 0;
		virtual void Draw() = 0;
	
	private:
		bool m_IsVisible;
		Vector2 m_Pos;
		Vector2 m_Size;

		friend class Page;
	};
}