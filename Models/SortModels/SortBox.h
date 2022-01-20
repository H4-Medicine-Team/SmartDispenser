#pragma once
#include <vector>
#include "Pill.h"
namespace Sorting {

	namespace Models {

		class SortBox
		{
		public:
			SortBox() = default;
			SortBox(const int boxId);

		public:
			inline int GetBoxId() { return boxId; };
			inline int GetPillAmount() { return pillAmount; }
			inline Pill GetPill() { return pill; }
			inline void SetBoxId(const int id) { boxId = id; }
			void SetPill(Pill _pill, const int amount);

		private:
			int boxId;
			int pillAmount;
			Pill pill;
		};
	}
}
