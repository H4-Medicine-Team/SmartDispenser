#include "SortBox.h"

namespace Sorting {

	namespace Models {
		SortBox::SortBox(const int boxId)
		{
			this->boxId = boxId;
		}
		void SortBox::SetPill(Pill _pill, const int amount)
		{
			pill = _pill;
			pillAmount = amount;
		}
	}

}
