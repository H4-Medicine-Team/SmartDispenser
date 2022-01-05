#pragma once

#include "Gui/SmdGui.h"

namespace Page {
	class MedicineCardPage : public Gui::Page {
	protected:
		void Start() override {
			Gui::ScrollViewStyle scrollStyle = {
				{128, 128, 128, 255},
				50,
				10,
				{35, 50},
				RED
			};

			Gui::ButtonStyle bStyle = {
				{255, 0, 0, 255},
				{0, 0, 0, 255},
				20
			};

			Gui::ScrollView* sc = new Gui::ScrollView({ 50, 25 }, { 700, 400 }, scrollStyle);

			for (int i = 0; i < 10; i++)
			{
				sc->Add(new Gui::Button(std::string("Hej ") + std::to_string(i), { 0, 0 }, { 0, 0 }, bStyle));
			}


			Add(sc);
		}
	};
}