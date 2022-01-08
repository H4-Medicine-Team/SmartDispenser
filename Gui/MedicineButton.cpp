#include "MedicineButton.h"

#include <functional>

namespace Gui {
	MedicineButton::MedicineButton(const Vector2& position, const Vector2& size)
		: Gui::Gui(position, size),
		m_Rectangle(position, size),
		m_DrugNameText("panodil", position),
		m_TimeText("11:00", position),
		m_AmountText("10/30", position),
		m_ClickCallback(NULL)
	{
		TextStyle defStyle{};
		defStyle.fontSize = 16;
		defStyle.color = WHITE;

		m_DrugNameText.SetDefaultStyle(defStyle);
		m_TimeText.SetDefaultStyle(defStyle);
		m_AmountText.SetDefaultStyle(defStyle);

		m_Rectangle.SetClickHandler(std::bind(&MedicineButton::RectangleOnClick, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		SetChildrenPos();
	}

	MedicineButton::~MedicineButton()
	{
	}

	void MedicineButton::SetPos(float x, float y)
	{
		Gui::SetPos(x, y);

		SetChildrenPos();
	}

	void MedicineButton::SetPos(const Vector2& pos)
	{
		SetPos(pos.x, pos.y);
	}

	void MedicineButton::SetSize(float x, float y)
	{
		Gui::SetSize(x, y);

		m_Rectangle.SetSize(x, y);

		SetChildrenPos();
	}

	void MedicineButton::SetSize(const Vector2& size)
	{
		SetSize(size.x, size.y);
	}

	void MedicineButton::SetData(const Dto::MedicineDto& data)
	{
		m_DrugNameText.SetText(data.name);
		m_TimeText.SetText(TmToString(data.time));
		m_AmountText.SetText(std::to_string(data.amount));

		SetChildrenPos();
	}

	void MedicineButton::SetClickHandler(const std::function<void(MedicineButton* btn, const Vector2& mousePos, bool isPressed)>& clickHandler)
	{
		m_ClickCallback = clickHandler;
	}

	void MedicineButton::SetChildrenPos()
	{
		const Vector2& pos = GetPos();
		const Vector2& center = GetCenter();
		const Vector2& size = GetSize();

		m_Rectangle.SetPos(pos);

		m_DrugNameText.SetPos(pos.x, center.y);
		m_TimeText.SetPos(pos.x + center.x - (m_TimeText.GetSize().x / 2), center.y);
		m_AmountText.SetPos(pos.x + size.x - m_AmountText.GetSize().x - 10, center.y);
	}

	void MedicineButton::RectangleOnClick(Rectangle* btn, const Vector2& mousePos, bool isPressed)
	{
		if (!m_ClickCallback)
			return;

		m_ClickCallback(this, mousePos, isPressed);
	}

	std::string MedicineButton::TmToString(const tm& tm)
	{
		return std::to_string(tm.tm_hour) + ":" + std::to_string(tm.tm_min);
	}

	void MedicineButton::Update()
	{
		m_Rectangle.Update();
		m_DrugNameText.Update();
		m_TimeText.Update();
		m_AmountText.Update();
	}

	void MedicineButton::Draw()
	{
		const Vector2& pos = GetPos();
		const Vector2& size = GetSize();

		m_Rectangle.Draw();
		m_DrugNameText.Draw();
		m_TimeText.Draw();
		m_AmountText.Draw();
	}
}