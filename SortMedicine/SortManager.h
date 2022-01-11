#pragma once
#include "../SortMedicine/SortDataCaller.h"
#include "ISortBoxesAccess.h"

namespace Sorting {

	class SortManager 
	{

	public:
		SortManager() = default;
		SortManager(ISortBoxesAccess* _access);

	private:
		ISortBoxesAccess* access;
	};
}

