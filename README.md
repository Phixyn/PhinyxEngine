# PhinyxEngine - A 2D Game Engine

**Author:** Alpeche Pancha

A simple 2D game engine developed using the SFML Framework. It is designed for 2D platform games. This implementation is for second assignment of the Game Engine Development module at the University of Suffolk.

Version 0.3.0 is the last planned release for this assignment, with development continuing on a fork of this repository.


## API Documentation

The API documentation was generated with [DoxyGen](http://www.stack.nl/~dimitri/doxygen/) and can be found in the `doc/html` folder. Open `index.html` in a web browser to get started.

## Compiled Static Library

PhinyxEngine can be used as a static library. See the project's [Releases](https://github.com/IMDCGP207-1617/game-engine-implementation-Phixyn/releases) for the latest `.lib` file.

## Example Game

The source code for an example game implementation can be found in the `ExampleGame` folder. The executable for the game, along with all needed assets to run it, can be found in the project's [Releases](https://github.com/IMDCGP207-1617/game-engine-implementation-Phixyn/releases). Please download the latest zip file from there and extract it to a folder. Run the `.exe` to run it.

## Project Dependencies

SFML 2.4 or higher is required to develop with the PhinyxEngine library. [Download it here.](https://www.sfml-dev.org/download.php) For instructions on setting up a project with SFML, read the ["Getting started" documentation.](https://www.sfml-dev.org/tutorials/2.4/)

## Level Creation

TODO

## Known Limitations

* No ability to pass sf::Style in window creation.
* Window resize not supported.
* No good handling of losing window focus.
* Framerate limited to 60.
* Limited player actions and keybinds.

## Planned features

* Input mapping to allow game developers (and players) to set their own keybinds and actions.
* Artificial Intelligence.
* More scene types, including main menu, splash screen, etc.
* Audio support.
* Animation handling.
* Debug panel.
* Game window resizing to a range of resolutions.
* Handling of entity health, attacks, scores, etc.
