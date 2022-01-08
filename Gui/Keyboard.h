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
		void SetText(const std::string& text);
		void SetTextChangedCallback(const std::function<void(const std::string& newText)>& callback);

		virtual void Update() override;
		virtual void Draw() override;

	private:
		void GenerateButtons(const std::vector<std::vector<const char*>>& layout);
		void OnButtonClick(Button* btn, const Vector2& mousePos, bool isPressed);

	private:
		std::vector<Gui*> m_Buttons;
		Button* m_Text;
		bool m_IsUp;

		std::function<void(const std::string& newText)> m_Callback;
	};
}