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
			/// Default constructor.
			/// </summary>
			///
			/// <param name="showTimestamps">
			/// A boolean specifying whether or not the log shows timestamps
			/// at the beginning of each line.
			/// </param>
			Logger(bool showTimestamps = true);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~Logger() { }

			/// <summary>
			/// TODO
			/// </summary>
			///
			/// <param name="level"> TODO </param>
			/// <param name="message"> TODO </param>
			void log(std::string level, std::string message);
		private:
			bool m_showTimestamps;
			std::time_t m_time_t = std::time(nullptr);
			struct std::tm *m_timeInfo = std::localtime(&m_time_t);
	};
}

#endif