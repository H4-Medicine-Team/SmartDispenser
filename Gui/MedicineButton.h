#pragma once
#include "Gui.h"
#include "Rectangle.h"
#include "Text.h"
#include "../Dto/MedicineCardDto.h"

namespace Gui {
	class MedicineButton :
		public Gui
	{
	public:
		MedicineButton(const Vector2& position, const Vector2& size);
		~MedicineButton();

	public:
		virtual void Update() override;
		virtual void Draw() override;

		void SetPos(float x, float y) override;
		void SetPos(const Vector2& pos) override;

		void SetSize(float x, float y) override;
		void SetSize(const Vector2& size) override;
		
		/*
		* Set all gui data from the medicine dto
		*/
		void SetData(const Dto::MedicineDto& data);

		/*
		* Set the click handler for when medicine button is clicked
		*/
		void SetClickHandler(const std::function<void(MedicineButton* btn, const Vector2& mousePos, bool isPressed)>& clickHandler);


	private:
		/*
		* Set the position for all the children
		*/
		void SetChildrenPos();

		/*
		* Called when the rectangle is clicked
		*/
		void RectangleOnClick(Rectangle* btn, const Vector2& mousePos, bool isPressed);

		/*
		* Convert Tm struct to a string
		*/
		std::string TmToString(const tm& tm);
	private:
		Rectangle m_Rectangle;
		Text m_DrugNameText;
		Text m_TimeText;
		Text m_AmountText;

		std::function<void(MedicineButton* btn, const Vector2& mousePos, bool isPressed)> m_ClickCallback;
	};
}