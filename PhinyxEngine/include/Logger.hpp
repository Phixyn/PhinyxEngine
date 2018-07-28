#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iomanip>
#include <ctime>

namespace PhinyxEngine
{
	/// <summary>
	/// Provides a very simple logging utility for the game engine.
	/// </summary>
	class Logger
	{
		public:
			/// <summary>
			/// Default constructor. Sets the m_showTimestamps member variable.
			/// </summary>
			///
			/// <param name="showTimestamps">
			/// A boolean specifying if timestamps are shown in log messages.
			/// Defaults to true.
			/// </param>
			Logger(bool showTimestamps = true);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~Logger() { }

			/// <summary>
			/// Writes a log message to STDOUT.
			/// </summary>
			///
			/// <param name="level">
			/// Level of importance of the log message (e.g. info).
			/// </param>
			/// <param name="message">
			/// The message to be logged.
			/// </param>
			void log(std::string level, std::string message);
		private:
			/// <summary>
			/// Boolean specifying if timestamps should appear in log messages.
			/// </summary>
			bool m_showTimestamps;
			std::time_t m_time_t = std::time(nullptr);

			/// <summary>
			/// <para> Structure to hold a calendar date and time broken down
			/// into its components. </para>
			/// <para> See also:
			/// <list type="bullet">
			/// <item> http://en.cppreference.com/w/c/chrono/tm </item>
			/// </list>
			/// </para>
			/// </summary>
			// struct tm m_timeInfo;
			struct std::tm *m_timeInfo = std::localtime(&m_time_t);
	};
}

#endif