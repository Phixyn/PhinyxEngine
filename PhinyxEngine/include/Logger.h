#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iomanip>
#include <ctime>

namespace PhinyxEngine {
	class Logger {
		public:
			Logger(bool showTimestamps = true);
			void log(std::string level, std::string message);
		private:
			bool m_showTimestamps;
			std::time_t m_time_t = std::time(nullptr);
			struct std::tm *m_timeInfo = std::localtime(&m_time_t);
	};
}

#endif