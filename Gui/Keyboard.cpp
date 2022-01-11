#include "Keyboard.h"
#include <functional>

namespace Gui {

	static std::vector<std::vector<const char*>> danish_layout = {
			{"ryd", "ok", "slet"},
			{"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"},
			{"q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "å"},
			{"a", "s", "d", "f", "g", "h", "j", "k", "l", "æ", "ø", "-"},
			{"op", "z", "x", "c", "v", "b", "n", "m", ",", "."},
			{"mellemrum"}
	};

	static std::vector<std::vector<const char*>> danish_layout_up = {
			{"ryd", "ok", "slet"},
			{"!", "@", "#", "$", "%", "&", "/", "(", ")", "="},
			{"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "Å"},
			{"A", "S", "D", "F", "G", "H", "J", "K", "L", "Æ", "Ø", "_"},
			{"op", "Z", "X", "C", "V", "B", "N", "M", ";", ":"},
			{"mellemrum"}
	};

	Keyboard::Keyboard(const Vector2& pos, const Vector2& size)
		: m_Buttons(),
		m_Text(),
		m_IsUp(false),
		m_Callback(NULL),
		Gui::Gui(pos, size)
	{
		SetIsVisible(false);
		GenerateButtons(danish_layout);
	}

	Keyboard::~Keyboard()
	{
		for (int i = 0; i < m_Buttons.size(); i++)
			delete m_Buttons[i];

		delete m_Text;
	}

	void Keyboard::GenerateButtons(const std::vector<std::vector<const char*>>& layout)
	{
		for (int i = 0; i < m_Buttons.size(); i++)
			delete m_Buttons[i];

		m_Buttons.clear();

		Vector2 pos = GetPos();
		Vector2 size = GetSize();

		int textHeight = 35;

		m_Text = new Button("", pos, {size.x, (float)textHeight});
		ButtonStyle style = m_Text->GetDefaultStyle();
		style.textStyle.fontSize = 18;
		style.textStyle.color = WHITE;
		style.rectangleStyle.borderSize = 0;
		style.rectangleStyle.rounding = 0;
		style.rectangleStyle.backgroundColor = { 104, 104, 104, 180 };

		m_Text->SetDefaultStyle(style);

		pos.y += textHeight;

		int btnHeight = (size.y - textHeight) / layout.size();

		for (int y = 0; y < layout.size(); y++)
		{
			int width = size.x / layout[y].size();

			const Vector2 btnSize = { width, btnHeight };

			for (int x = 0; x < layout[y].size(); x++)
			{
				Vector2 btnPos = {pos.x + width * x, pos.y + btnHeight * y};
				auto btn = new Button(layout[y][x], btnPos, btnSize);
				btn->SetClickHandler(std::bind(&Keyboard::OnButtonClick, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

				m_Buttons.push_back(btn);
			}
		}
	}

	void Keyboard::OnButtonClick(Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (isPressed)
			return;

		std::string curText = m_Text->GetText();
		const std::string& btnText = btn->GetText();

		if (btnText == "mellemrum")
			curText.append(" ");
		else if (btnText == "ryd")
			curText.clear();
		else if (btnText == "ok")
			SetIsVisible(false);
		else if (btnText == "slet")
		{
			if (curText.size() != 0)
				curText.pop_back();
		}
		else if (btnText == "op")
		{
			if (m_IsUp)
				GenerateButtons(danish_layout);
			else
				GenerateButtons(danish_layout_up);

			m_IsUp = !m_IsUp;
		}
		else
			curText.append(btn->GetText());

		m_Text->SetText(curText);

		if (m_Callback)
			m_Callback(curText);
	}

	void Keyboard::SetText(const std::string& text)
	{
		m_Text->SetText(text);
	}

	void Keyboard::Update()
	{
		if (!IsVisible())
			return;

		for (int i = 0; i < m_Buttons.size(); i++)
			m_Buttons[i]->Update();

		m_Text->Update();
	}

	void Keyboard::Draw()
	{
		if (!IsVisible())
			return;

		for (int i = 0; i < m_Buttons.size(); i++)
			m_Buttons[i]->Draw();

		m_Text->Draw();
	}

	void Keyboard::SetTextChangedCallback(const std::function<void(const std::string& newText)>& callback)
	{
		m_Callback = callback;
	}
}