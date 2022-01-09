#pragma once
#include "Gui.h"
#include <Raylib.h>
#include <vector>
#include "Button.h"

namespace Gui {
	class Keyboard : public Gui
	{
	public:
		Keyboard(const Vector2& pos, const Vector2& size);
		~Keyboard();

	public:
		/*
		* Set the text for the keyboard
		*/
		void SetText(const std::string& text);

		/*
		* Set the text changed callback, for when a letter has been clicked.
		*/
		void SetTextChangedCallback(const std::function<void(const std::string& newText)>& callback);

		virtual void Update() override;
		virtual void Draw() override;

	private:
		/*
		* Generates the layout of the keyboard in gui elements
		*/
		void GenerateButtons(const std::vector<std::vector<const char*>>& layout);

		/*
		* Keyboard button click handler
		* btn -> The current button which was pressed
		* mousePos -> The current position of the mouse
		* isPressed -> Whether the mouse is down or up
		*/
		void OnButtonClick(Button* btn, const Vector2& mousePos, bool isPressed);

	private:
		std::vector<Gui*> m_Buttons;
		Button* m_Text;
		bool m_IsUp;

		std::function<void(const std::string& newText)> m_Callback;
	};
}