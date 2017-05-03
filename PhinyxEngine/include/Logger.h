#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iomanip>
#include <ctime>

namespace PhinyxEngine
{
	/// <summary>
	/// Class for the logging utility of the game engine. Provides a method
	/// to log messages to the console.
	/// </summary>
	class Logger
	{
		public:
			/// <summary>
			/// TODO
			/// </summary>
			///
			/// <param name="showTimestamps"> </param>
			Logger(bool showTimestamps = true);

			/// <summary>
			/// TODO
			/// </summary>
			///
			/// <param name="level"> </param>
			/// <param name="message"> </param>
			void log(std::string level, std::string message);
		private:
			bool m_showTimestamps;
			std::time_t m_time_t = std::time(nullptr);
			struct std::tm *m_timeInfo = std::localtime(&m_time_t);
	};
}

#endif