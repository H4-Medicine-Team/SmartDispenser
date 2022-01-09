#pragma once

#include <Gui/Rectangle.h>
#include <Gui/Text.h>

namespace Gui {
	class EditButton : public Gui
	{
	public:
		EditButton(const std::string& constText, const std::string& editableText, const Vector2& pos, const Vector2& size);
		~EditButton();

	public:
		virtual void Update() override;
		virtual void Draw() override;

		virtual void SetPos(const Vector2& pos) override;
		virtual void SetPos(float x, float y) override;
		virtual void SetSize(const Vector2& size) override;
		virtual void SetSize(float w, float h) override;

		/*
		* Set default style for the text and the rectangle
		*/
		void SetDefaultStyle(const TextStyle& textStyle, const RectangleStyle& rectStyle);

		/*
		* Set hover style for the text and the rectangle
		*/
		void SetHoverStyle(const TextStyle& textStyle, const RectangleStyle& rectStyle);

		/*
		* Set the text for the editable text
		*/
		void SetText(const std::string& text);

		/*
		* Set click handler for when clicking rectangle
		*/
		void SetClickHandler(const std::function<void(EditButton* btn, const Vector2& mousePos, bool isPressed)>& clickHandler);

		/*
		* Get the editable text
		*/
		const std::string& GetText();

		/*
		* Called when the rectangle is clicked
		*/
		void RectangleOnClick(Rectangle* btn, const Vector2& mousePos, bool isPressed);

	private:

		/*
		* Setup the childrens position and size.
		*/
		void SetupChildren();
	private:
		Rectangle m_Rectangle;
		Text m_ConstText;
		Text m_EditableText;

		std::function<void(EditButton* btn, const Vector2& mousePos, bool isPressed)> m_ClickCallback;
	};
}