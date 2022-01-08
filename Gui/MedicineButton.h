#pragma once
#include "Gui.h"
#include "Rectangle.h"
#include "Text.h"

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

		void SetClickHandler(const std::function<void(MedicineButton* btn, const Vector2& mousePos, bool isPressed)>& clickHandler);

	private:
		void SetChildrenPos();
		void RectangleOnClick(Rectangle* btn, const Vector2& mousePos, bool isPressed);
	private:
		Rectangle m_Rectangle;
		Text m_DrugNameText;
		Text m_TimeText;
		Text m_AmountText;

		std::function<void(MedicineButton* btn, const Vector2& mousePos, bool isPressed)> m_ClickCallback;
	};
}