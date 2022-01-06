#pragma once
#include <Raylib.h>

namespace Gui {
	class Gui {
	public:
		Gui(const Vector2& position, const Vector2& size) 
			: m_IsVisible(true), 
			m_Pos(position),
			m_Size(size) {};

		// Get the current position for the gui element
		const Vector2& GetPos() { return m_Pos; }

		// get the size for the current gui element
		const Vector2& GetSize() { return m_Size; }

		// Get center position for gui element
		const Vector2 GetCenter() { return { m_Pos.x + (m_Size.x / 2), m_Pos.y + (m_Size.y / 2) }; }

		// Get whether the gui element is visible or not
		const bool IsVisible() { return m_IsVisible; }

		// Set visibility
		void SetIsVisible(bool visible) { m_IsVisible = visible; }

		// Set the gui elements position: top-left
		void SetPos(const Vector2& pos) { m_Pos = pos; }

		// Set the gui elements position: top-left
		void SetPos(float x, float y) { m_Pos = { x, y }; }

		// Set the gui elements size
		void SetSize(const Vector2& pos) { m_Size = pos; }

		// Set the gui elements size
		void SetSize(float w, float h) { m_Size = { w, h }; }

		// Adds position to the current for the element: top-left
		void Translate(const Vector2& pos) { m_Pos.x += pos.x; m_Pos.y += pos.y; }

		// Adds position to the current for the element: top-left
		void Translate(float x, float y) { m_Pos.x += x; m_Pos.y += y; }

	public:
		// Is called each frame and updates the gui element
		virtual void Update() = 0;

		// Is called each frame and draws the gui element
		virtual void Draw() = 0;
	
	private:
		bool m_IsVisible;
		Vector2 m_Pos;
		Vector2 m_Size;

		friend class Page;
	};
}