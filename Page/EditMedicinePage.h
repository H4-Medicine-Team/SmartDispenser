#pragma once
#include <Gui/Page.h>
#include <Dto/MedicineCardDto.h>
#include <DataAccess/LocalDb.h>
#include <Gui/Button.h>
#include <Gui/EditButton.h>

namespace Page {
	class EditMedicinePage : public Gui::Page
	{
	public:
		EditMedicinePage(Dto::MedicineDto medicine, bool isEditing);
		~EditMedicinePage();

	private:
		/*
		* Called when name button has been clicked
		*/
		void NameClickCallback(Gui::EditButton* btn, const Vector2& mousePos, bool isPressed);

		/*
		* Called when time button has been clicked
		*/
		void TimeClickCallback(Gui::EditButton* btn, const Vector2& mousePos, bool isPressed);

		/*
		* Called when the amount button is clicked
		*/
		void AmountClickCallback(Gui::EditButton* btn, const Vector2& mousePos, bool isPressed);

		/*
		* Called when the update button is clicked
		*/
		void UpdateClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed);

		/*
		* Called when the delete button is clicked
		*/
		void DeleteClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed);

		/*
		* Called when the add button is clicked
		*/
		void AddMedicineClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed);

		/*
		* Called when the name text has changed on the keyboard
		*/
		void NameChangedCallback(const std::string& text);
		/*
		* Called when the time text has changed on the keyboard
		*/
		void TimeChangedCallback(const std::string& text);
		/*
		* Called when the amount text has changed on the keyboard
		*/
		void AmountChangedCallback(const std::string& text);

		/*
		* Convert tm to std::string
		*/
		std::string ConvertTimeToString(const tm& tm);

		/*
		* Splits a string from the given delimiter c
		*/
		std::vector<std::string> SplitString(const std::string& string, char c);

	private:
		Dto::MedicineDto m_OriginalMedicine;
		Gui::EditButton* m_NameButton;
		Gui::EditButton* m_TimeButton;
		Gui::EditButton* m_AmountButton;
		DataAccess::LocalDb m_Database;
	};
}