#pragma once
#include <string>

namespace Sorting {

	namespace Models {
		class Pill
		{
		public:
			Pill() = default;
			Pill(const std::string _name, const int _id, const std::string _external_id);

		public:
			inline std::string GetName() { return name; }
			inline int GetID() { return id; }
			inline std::string GetExternalID() { return externalID; }
		private:
			int id;
			std::string name;
			std::string externalID;
		};
	}
}

