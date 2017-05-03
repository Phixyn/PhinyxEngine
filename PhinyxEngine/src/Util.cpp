#include "../include/Util.h"

std::vector<std::string> PhinyxEngine::Util::stringSplit(std::string const &stringData, char token)
{
	// TODO: Add error handling?
	std::vector<std::string> resultVector;

	// Iterators for the string
	std::string::const_iterator startPos = stringData.begin();
	std::string::const_iterator endPos = stringData.end();
	std::string::const_iterator matchPos = std::find(startPos, endPos, token);

	while (matchPos != endPos)
	{
		resultVector.push_back(std::string(startPos, matchPos));
		startPos = matchPos + 1;
		matchPos = std::find(startPos, endPos, token);
	}

	// Push the last string found to the vector and return it
	resultVector.push_back(std::string(startPos, matchPos));
	return resultVector;
}