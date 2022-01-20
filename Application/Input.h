#pragma once
#include <Raylib.h>
#include <functional>

namespace Application {

	class Input
	{
	// Singleton
	public:
		/*
		* Get singleton reference of input
		*/
		static Input& Get() { static Input instance; return instance; }

		Input(Input const&) = delete;
		void operator=(Input const&) = delete;
	private:
		Input() {};
		~Input() {};
	public:
		/*
		* Get mouse position
		*/
		const Vector2& GetMPosition() { return m_MousePosition; }
		
		/*
		* Get touch position
		*/
		const Vector2& GetTPosition() { return m_TouchPosition; }

		/*
		* Get the delta time for the current frame and last.
		*/
		const float& GetDelta() { return m_DeltaTime; }

		/*
		* the mouse and touch position
		*/
		void Update();

	private:
		Vector2 m_MousePosition;
		Vector2 m_TouchPosition;

		float m_DeltaTime;
	};
}


