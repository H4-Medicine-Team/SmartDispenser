#include "EditMedicinePage.h"
#include <Gui/PageHandler.h>
#include "MedicineCardPage.h"
#include <sstream>

namespace Page {

	static void backCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {
		if (isPressed)
			return;

		Gui::PageHandler::Get().Load<MedicineCardPage>();
	}

	EditMedicinePage::EditMedicinePage(Dto::MedicineDto medicine)
		: m_Database(),
		m_NameButton(NULL),
		m_TimeButton(NULL),
		m_AmountButton(NULL),
		m_OriginalMedicine(medicine)
	{
		Gui::ButtonStyle style{};
		style.textStyle.fontSize = 25;
		style.textStyle.color = BLACK;
		style.rectangleStyle.backgroundColor = { 255, 255, 255, 255 };
		style.rectangleStyle.borderSize = 0;
		style.rectangleStyle.rounding = 0;

		Gui::Button* backBtn = new Gui::Button("Back", { 10, 10 }, { 50, 35 });
		backBtn->SetClickHandler(backCallback);

		m_NameButton = new Gui::Button(medicine.name, { 350, 50 }, {100, 50});
		m_NameButton->SetClickHandler(std::bind(&EditMedicinePage::NameClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		m_NameButton->SetDefaultStyle(style);

		m_TimeButton = new Gui::Button(ConvertTimeToString(medicine.time), { 250, 150 }, { 100, 50 });
		m_TimeButton->SetClickHandler(std::bind(&EditMedicinePage::TimeClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		m_TimeButton->SetDefaultStyle(style);

		m_AmountButton = new Gui::Button(std::to_string(medicine.amount), { 450, 150 }, { 100, 50 });
		m_AmountButton->SetClickHandler(std::bind(&EditMedicinePage::AmountClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		m_AmountButton->SetDefaultStyle(style);

		Gui::Button* updateBtn = new Gui::Button("Opdater", { 250, 400 }, { 100, 50 });
		updateBtn->SetClickHandler(std::bind(&EditMedicinePage::UpdateClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

		Gui::Button* deleteBtn = new Gui::Button("Slet", { 500, 400 }, { 100, 50 });

		Add(m_NameButton);
		Add(m_TimeButton);
		Add(m_AmountButton);
		Add(backBtn);
		Add(updateBtn);
		Add(deleteBtn);
	}

	EditMedicinePage::~EditMedicinePage()
	{
	}

	void EditMedicinePage::NameChangedCallback(const std::string& text)
	{
		m_NameButton->SetText(text);
	}

	void EditMedicinePage::TimeChangedCallback(const std::string& text)
	{
		m_TimeButton->SetText(text);
	}

	void EditMedicinePage::AmountChangedCallback(const std::string& text)
	{
		m_AmountButton->SetText(text);
	}

	std::string EditMedicinePage::ConvertTimeToString(const tm& tm)
	{
		return std::to_string(tm.tm_hour) + ":" + std::to_string(tm.tm_min);
	}

	std::vector<std::string> EditMedicinePage::SplitString(const std::string& string, char c)
	{
		auto vec = std::vector<std::string>();
		std::istringstream f(string);

		std::string s;
		while (getline(f, s, ';')) {
			vec.push_back(s);
		}

		return vec;
	}

	void EditMedicinePage::NameClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (isPressed)
			return;

		GetKeyboard().SetText(btn->GetText());
		GetKeyboard().SetIsVisible(true);
		GetKeyboard().SetTextChangedCallback(std::bind(&EditMedicinePage::NameChangedCallback, this, std::placeholders::_1));
	}

	void EditMedicinePage::TimeClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (isPressed)
			return;

		GetKeyboard().SetText(btn->GetText());
		GetKeyboard().SetIsVisible(true);
		GetKeyboard().SetTextChangedCallback(std::bind(&EditMedicinePage::TimeChangedCallback, this, std::placeholders::_1));
	}

	void EditMedicinePage::AmountClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (isPressed)
			return;

		GetKeyboard().SetText(btn->GetText());
		GetKeyboard().SetIsVisible(true);
		GetKeyboard().SetTextChangedCallback(std::bind(&EditMedicinePage::AmountChangedCallback, this, std::placeholders::_1));
	}

	void EditMedicinePage::UpdateClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (isPressed)
			return;

		m_OriginalMedicine.name = m_NameButton->GetText();
		m_OriginalMedicine.amount = std::stoi(m_AmountButton->GetText());

		const std::string& time = m_TimeButton->GetText();
		auto times = SplitString(time, ':');
		
		if (times.size() == 2)
		{
			m_OriginalMedicine.time.tm_hour = std::stoi(times[0]);
			m_OriginalMedicine.time.tm_min = std::stoi(times[1]);
		}

		m_Database.EditMedicine(m_OriginalMedicine);
		Gui::PageHandler::Get().Load<MedicineCardPage>();
	}

	void EditMedicinePage::DeleteClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
	{
		if (isPressed)
			return;

		m_Database.RemoveMedicine(m_OriginalMedicine);

		Gui::PageHandler::Get().Load<MedicineCardPage>();
	}
}
