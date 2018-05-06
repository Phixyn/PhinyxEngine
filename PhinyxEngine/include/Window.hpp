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
			/// <summary> Default constructor. </summary>
			///
			/// <param name="WIDTH"> The width of the window. </param>
			/// <param name="HEIGHT"> The height of the window. </param>
			/// <param name="TITLE"> A title for the window. </param>
			/// <param name="showDebugPane"> A title for the window. </param>
			Window(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~Window() { }

			/// <summary> Clears the window by calling the clear method on the
			/// SFML Window instance. </summary>
			void clear();

			/// <summary> Calls the display method of the SFML Window to render
			/// the window. </summary>
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
			/// <summary> Draws a SFML RectangleShape on the window. </summary>
			///
			/// <param name="rect"> Instance of SFML RectangleShape to be drawn
			/// on the window. </param>
			void drawRect(sf::RectangleShape rect);

			/// <summary>
			/// Draws the SFML RectangleShape objects in the paramater's vector
			/// onto the SFML Window.
			/// </summary>
			///
			/// <param name="rectVector"> A std::vector containing instances
			/// of SFML RectangleShape to be drawn on the window. </param>
			void drawRectVector(std::vector<sf::RectangleShape> rectVector);

			/// <summary> Draws SFML Text onto the window. </summary>
			/// <param name="text"> Instance of SFML Text to be drawn on the window. </param>
			void drawText(sf::Text text);

			/// <summary> Handles SFML events received in the window. </summary>
			void handleEvents();

			bool isOpen() const;

			/// <returns> A boolean indicating if the window has focus. </returns>
			bool hasFocus() const;

			/// <returns> The width of the window. </returns>
			unsigned int getWidth() const;

			/// <returns> The height of the window. </returns>
			unsigned int getHeight() const;

			/// <summary> Returns a string containing the title of the window. </summary>
			/// <returns> A std::string containing the title of the window. </returns>
			std::string getTitle() const;

			// View for the game, this could be moved to the game class in the future
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

			bool m_showDebugPane;
			/// <summary> Boolean specifying if the window has focus.
			/// This member variable is set in handleEvents() method. </summary>
			bool m_hasFocus;
			unsigned int m_WIDTH;
			unsigned int m_HEIGHT;
			std::string m_TITLE;
			std::unique_ptr<sf::RenderWindow> m_window;

			sf::RectangleShape m_debugPane;
			sf::Text m_debugTextDeltaTimer;
			sf::Font m_debugPaneFont;

			Logger m_logger;
	};
}

#endif
