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

	EditMedicinePage::EditMedicinePage(Dto::MedicineDto medicine, bool isEditing)
		: m_Database(),
		m_NameButton(NULL),
		m_TimeButton(NULL),
		m_AmountButton(NULL),
		m_OriginalMedicine(medicine)
	{
		Vector2 editableButtonSize = { 200, 50 };
		Vector2 operationButtonSize = { 100, 50 };

		Gui::TextStyle textStyle{};
		textStyle.fontSize = 20;
		textStyle.color = BLACK;

		Gui::RectangleStyle rectStyle{};
		rectStyle.backgroundColor = { 255, 255, 255, 255 };
		rectStyle.borderSize = 0;
		rectStyle.rounding = 0;

		Gui::ButtonStyle style{};
		style.textStyle = textStyle;
		style.rectangleStyle = rectStyle;

		Gui::TextStyle textHoverStyle = textStyle;

		Gui::RectangleStyle rectHoverStyle = rectStyle;
		rectHoverStyle.backgroundColor = { 255, 255, 255, 255 };
		rectHoverStyle.borderColor = { 0, 0, 0, 255 };
		rectHoverStyle.borderSize = 2;
		rectHoverStyle.rounding = 0.3f;

		Gui::Button* backBtn = new Gui::Button("Back", { 10, 10 }, { 50, 35 });
		backBtn->SetClickHandler(backCallback);

		m_NameButton = new Gui::EditButton("Navn: ", medicine.name, {400 - editableButtonSize.x / 2, 50}, editableButtonSize);
		m_NameButton->SetClickHandler(std::bind(&EditMedicinePage::NameClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		m_NameButton->SetDefaultStyle(textStyle, rectStyle);
		m_NameButton->SetHoverStyle(textHoverStyle, rectHoverStyle);

		m_TimeButton = new Gui::EditButton("Tid: ", ConvertTimeToString(medicine.time), {200 - editableButtonSize.x / 2, 150}, editableButtonSize);
		m_TimeButton->SetClickHandler(std::bind(&EditMedicinePage::TimeClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		m_TimeButton->SetDefaultStyle(textStyle, rectStyle);
		m_TimeButton->SetHoverStyle(textHoverStyle, rectHoverStyle);

		m_AmountButton = new Gui::EditButton("Stykker: ", std::to_string(medicine.amount), {600 - editableButtonSize.x / 2, 150}, editableButtonSize);
		m_AmountButton->SetClickHandler(std::bind(&EditMedicinePage::AmountClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		m_AmountButton->SetDefaultStyle(textStyle, rectStyle);
		m_AmountButton->SetHoverStyle(textHoverStyle, rectHoverStyle);


		if (isEditing)
		{
			Gui::Button* updateBtn = new Gui::Button("Opdater", { 200 - operationButtonSize.x / 2, 400 }, operationButtonSize);
			updateBtn->SetClickHandler(std::bind(&EditMedicinePage::UpdateClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

			Gui::Button* deleteBtn = new Gui::Button("Slet", { 600 - operationButtonSize.x / 2, 400 }, operationButtonSize);
			deleteBtn->SetClickHandler(std::bind(&EditMedicinePage::DeleteClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

			Add(updateBtn);
			Add(deleteBtn);
		}
		else
		{
			Gui::Button* addBtn = new Gui::Button("Tilfoej", { 400 - (operationButtonSize.x * 2) / 2, 400 }, { operationButtonSize.x * 2, operationButtonSize.y });
			addBtn->SetClickHandler(std::bind(&EditMedicinePage::AddMedicineClickCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
			
			Add(addBtn);
		}
		
		Add(m_NameButton);
		Add(m_TimeButton);
		Add(m_AmountButton);
		Add(backBtn);
		
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
		char* text = new char[100];
		strftime(text, 100, "%R", &tm);
		std::string v = std::string(text);
		delete text;
		return v;
	}

	std::vector<std::string> EditMedicinePage::SplitString(const std::string& string, char c)
	{
		auto vec = std::vector<std::string>();
		std::istringstream f(string);

		std::string s;
		while (getline(f, s, c)) {
			vec.push_back(s);
		}

		return vec;
	}

	void EditMedicinePage::NameClickCallback(Gui::EditButton* btn, const Vector2& mousePos, bool isPressed)
	{
		if (isPressed)
			return;

		GetKeyboard().SetText(btn->GetText());
		GetKeyboard().SetIsVisible(true);
		GetKeyboard().SetTextChangedCallback(std::bind(&EditMedicinePage::NameChangedCallback, this, std::placeholders::_1));
	}

	void EditMedicinePage::TimeClickCallback(Gui::EditButton* btn, const Vector2& mousePos, bool isPressed)
	{
		if (isPressed)
			return;

		GetKeyboard().SetText(btn->GetText());
		GetKeyboard().SetIsVisible(true);
		GetKeyboard().SetTextChangedCallback(std::bind(&EditMedicinePage::TimeChangedCallback, this, std::placeholders::_1));
	}

	void EditMedicinePage::AmountClickCallback(Gui::EditButton* btn, const Vector2& mousePos, bool isPressed)
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

	void EditMedicinePage::AddMedicineClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed)
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

		m_Database.InsertMedicine(m_OriginalMedicine);

		Gui::PageHandler::Get().Load<MedicineCardPage>();
	}
}
