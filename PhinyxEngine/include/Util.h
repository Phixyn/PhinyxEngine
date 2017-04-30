#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>

namespace PhinyxEngine {
	class Util {
		public:
			static std::vector<std::string> stringSplit(std::string const& stringData, char token);
	};
}

#endif