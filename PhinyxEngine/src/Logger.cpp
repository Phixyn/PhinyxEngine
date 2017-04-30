#include "../include/Logger.h"
#include <sstream>
#include <iostream>

PhinyxEngine::Logger::Logger(bool showTimestamps) : m_showTimestamps(showTimestamps) {

}

void PhinyxEngine::Logger::log(std::string level, std::string message) {
	std::ostringstream oss;
	
	if (m_showTimestamps == true) {
		oss << std::put_time(m_timeInfo, "[%d-%m-%Y %H:%M:%S]");
	}

	oss << "[" << level << "]: " << message << std::endl;
	std::cout << oss.str();
}

