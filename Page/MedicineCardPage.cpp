#include "MedicineCardPage.h"

#include "../Gui/Button.h"
#include "../Gui/PageHandler.h"
#include "../Page/EditMedicinePage.h"

#include "MainPage.h"


namespace Page {
	static void backCallback(Gui::Button* btn, const Vector2& mousePos, bool isPressed) {

		if (!isPressed)
			Gui::PageHandler::Get().Load<MainPage>();
	}

	MedicineCardPage::MedicineCardPage() 
		: m_Database(),
		m_Data(NULL),
		m_ScrollView(NULL)
	{
		GetMedicineData();
	}

	MedicineCardPage::~MedicineCardPage()
	{
		delete m_Data;
	}

	void MedicineCardPage::OnMedicineClick(Gui::MedicineButton* btn, const Vector2& mousePos, bool isPressed)
	{
		if (isPressed)
			return;

		int currentIndex = m_ScrollView->GetElementIndex(btn);
		if (currentIndex == -1)
			return;

		const Dto::MedicineDto& dto = (*m_Data)[currentIndex];

		Gui::PageHandler::Get().Load<EditMedicinePage>(dto);
	}

	void MedicineCardPage::GetMedicineData()
	{
		Gui::Button* backBtn = new Gui::Button("Back", { 10, 10 }, { 50, 35 });
		backBtn->SetClickHandler(backCallback);

		Clear();
		m_Data = m_Database.GetMedicineCard();

		m_ScrollView = new Gui::ScrollView({ 0, 50 }, { 800, 320 }, { 25, 40 });

		for (int i = 0; i < m_Data->size(); i++)
		{
			auto btn = new Gui::MedicineButton({}, {});
			btn->SetData((*m_Data)[i]);
			btn->SetClickHandler(std::bind(&MedicineCardPage::OnMedicineClick, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
			m_ScrollView->Add(btn);
		}

		Gui::Button* insertBtn = new Gui::Button("Tilføj", { 20, 380 }, { 760, 50 });

		Add(m_ScrollView);
		Add(insertBtn);
		Add(backBtn);
	}
}