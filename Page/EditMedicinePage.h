#pragma once
#include "../Gui/Page.h"
#include "../Dto/MedicineCardDto.h"
#include "../DataAccess/LocalDb.h"
#include "../Gui/Button.h"

namespace Page {
	class EditMedicinePage : public Gui::Page
	{
	public:
		EditMedicinePage(Dto::MedicineDto medicine);
		~EditMedicinePage();

	private:
		void NameClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed);
		void TimeClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed);
		void AmountClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed);
		void UpdateClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed);
		void DeleteClickCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed);

		void NameChangedCallback(const std::string& text);
		void TimeChangedCallback(const std::string& text);
		void AmountChangedCallback(const std::string& text);

		std::string ConvertTimeToString(const tm& tm);

		std::vector<std::string> SplitString(const std::string& string, char c);

	private:
		Dto::MedicineDto m_OriginalMedicine;
		Gui::Button* m_NameButton;
		Gui::Button* m_TimeButton;
		Gui::Button* m_AmountButton;
		DataAccess::LocalDb m_Database;
	};
}