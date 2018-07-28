#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>

namespace PhinyxEngine
{
	/// <summary>
	/// Utility class providing various miscellaneous methods used throughout
	/// the game engine.
	/// </summary>
	class Util
	{
		public:
			/// <summary>
			/// Splits a string by a given token into a vector. The token
			/// can be any character. A common use for this is parsing
			/// configuration files and level files (e.g. splitting a
			/// key-value pair by the '=' character).
			/// </summary>
			///
			/// <param name="stringData">
			/// A reference to the string to be split.
			/// </param>
			/// <param name="token">
			/// Token by which to split the string.
			/// </param>
			///
			/// <returns>
			/// A vector containing all the results of the string split
			/// operation.
			/// </returns>
			static std::vector<std::string> stringSplit(std::string const &stringData, char token);
	};
}

#endif