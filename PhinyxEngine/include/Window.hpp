#ifndef WINDOW_H
#define WINDOW_H

#include "Logger.hpp"
#include <string>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

namespace PhinyxEngine
{
	/// <summary>
	/// Class for creating and managing a game window.
	/// </summary>
	class Window
	{
		public:
			/// <summary>
			/// Default constructor. Creates an SFML RenderWindow with the
			/// given properties.
			/// </summary>
			///
			/// <param name="WIDTH"> The width of the window. </param>
			/// <param name="HEIGHT"> The height of the window. </param>
			/// <param name="TITLE"> A title for the window. </param>
			/// <param name="showDebugPane"> A boolean specifying whether the
			/// debug panel should be displayed. </param>
			Window(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~Window() { }

			/// <summary>
			/// Polls the SFML Window for events received in the window, and
			/// handles them appropriately.
			/// </summary>
			void handleEvents();
			/// <summary>
			/// Clears the window by calling the clear method on the SFML
			/// RenderWindow instance.
			/// </summary>
			void clear();
			/// <summary>
			/// Resets the view (<see cref="m_view">m_view</see>) inside the
			/// window and calls the display method of the SFML RenderWindow
			/// to render the window.
			/// </summary>
			void render();

			/// <summary>
			/// Draws a SFML Drawable object on the window.
			/// </summary>
			///
			/// <param name="drawable">
			/// Reference to the SFML Drawable instance to be drawn on the
			/// window.
			/// </param>
			void draw(const sf::Drawable &drawable);
			// TODO: these methods are not needed, should just use the above
			/// <summary>
			/// Draws a SFML RectangleShape on the window.
			/// </summary>
			///
			/// <param name="rect">
			/// Instance of SFML RectangleShape to be drawn on the window.
			/// </param>
			void drawRect(sf::RectangleShape rect);
			/// <summary>
			/// Draws the SFML RectangleShape objects in the paramater's vector
			/// onto the SFML Window.
			/// </summary>
			///
			/// <param name="rectVector">
			/// A std::vector containing instances of SFML RectangleShape to be
			/// drawn on the window.
			/// </param>
			void drawRectVector(std::vector<sf::RectangleShape> rectVector);
			/// <summary>
			/// Draws SFML Text onto the window.
			/// </summary>
			///
			/// <param name="text">
			/// Instance of SFML Text to be drawn on the window.
			/// </param>
			void drawText(sf::Text text);

			/// <returns>
			/// A boolean indicating if the window is open.
			/// </returns>
			bool isOpen() const;
			/// <returns>
			/// A boolean indicating if the window has focus.
			/// </returns>
			bool hasFocus() const;
			/// <returns>
			/// The width of the window.
			/// </returns>
			unsigned int getWidth() const;
			/// <returns>
			/// The height of the window.
			/// </returns>
			unsigned int getHeight() const;
			/// <summary>
			/// Returns a string containing the title of the window.
			/// </summary>
			///
			/// <returns>
			/// A string object containing the title of the window.
			/// </returns>
			std::string getTitle() const;

			/// <summary>
			/// SFML View instance for the game window.
			///
			/// TODO: This could be moved to the game class in the future.
			/// </summary>
			sf::View m_view;
		private:
			/// <summary>
			/// Resizes the game's view and its contents proportionally to an
			/// aspect ratio.
			/// </summary>
			///
			/// <param name="window">
			/// A reference to the SFML Window instance that has the view.
			/// </param>
			/// <param name="view">
			/// A reference to the SFML View to be resized.
			/// </param>
			void resizeView(sf::Window &window, sf::View &view);

			/// <summary>
			/// Boolean specifying if the debug pane should be displayed in the
			/// game window. Defaults to true in the constructor.
			/// </summary>
			bool m_showDebugPane;
			/// <summary>
			/// Boolean specifying if the window has focus.
			/// This member variable is set in handleEvents() method.
			/// </summary>
			bool m_hasFocus;
			// TODO: Rename these to lowercase?
			/// <summary>
			/// Width of the game window.
			/// </summary>
			unsigned int m_WIDTH;
			/// <summary>
			/// Height of the game window.
			/// </summary>
			unsigned int m_HEIGHT;
			/// <summary>
			/// Title of the game window seen on the titlebar.
			/// </summary>
			std::string m_TITLE;
			/// <summary>
			/// Unique pointer to a SFML RenderWindow object.
			/// </summary>
			std::unique_ptr<sf::RenderWindow> m_window;

			/// <summary>
			/// Instance of SFML RectangleShape for the debug panel, which is
			/// used to display game and entity debug information on screen.
			/// </summary>
			sf::RectangleShape m_debugPane;
			/// <summary>
			/// Instance of SFML Text used to make text drawables for the debug
			/// panel's text contents.
			/// </summary>
			sf::Text m_debugTextDeltaTimer;
			/// <summary>
			/// Instance of SFML Font for the font to be used in debug info text.
			/// </summary>
			sf::Font m_debugPaneFont;
			
			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif
