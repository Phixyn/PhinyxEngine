# PhinyxEngine - A 2D Game Engine

**Author:** Alpeche Pancha

A simple 2D game engine developed using the SFML Framework. It is designed for 2D platform games. This implementation is for second assignment of the Game Engine Development module at the University of Suffolk.

Version 0.3.0 is the last planned release for this assignment, with development continuing on a fork of this repository.

## API Documentation

The API documentation was generated with [DoxyGen](http://www.stack.nl/~dimitri/doxygen/) and can be found in the `doc/html` folder. Open `index.html` in a web browser to get started.

## Usage

PhinyxEngine can be linked as a library when compiling your game. See the project's [Releases](https://github.com/IMDCGP207-1617/game-engine-implementation-Phixyn/releases) for the latest `.lib` file.

## Example Game

The source code for an example game implementation can be found in the `ExampleGame` folder. The executable for the game, along with all needed assets to run it, can be found in the project's [Releases](https://github.com/IMDCGP207-1617/game-engine-implementation-Phixyn/releases). Please download the latest zip file from there and extract it to a folder. Run the `.exe` to run it.

## Project Dependencies

SFML 2.4 or higher is required to develop with the PhinyxEngine library. [Download it here.](https://www.sfml-dev.org/download.php) For instructions on setting up a project with SFML, read the ["Getting started" documentation.](https://www.sfml-dev.org/tutorials/2.4/)

For convenience, the necessary header files and DLLs are provided in this repo.

## Level Creation

A single level can be made with two text files. The first text file is the level file, ending with the extension `.lvl`. This file is no more than a grid with numbers separated by a pipe `|`  character. The numbers represent the types of tiles in the level. When the level is loaded, each tile in the grid will be drawn depending on the numbers. Thus, each tile needs to have a texture file specified for it.

The textures for each tile are specified in another text file `.dat`. Note that both `.lvl` and `.dat` files have to be present and named the same for a single level (e.g. `level1.lvl` and `level1.dat`).

The file paths for the textures `.dat` should be relative to where the game's executable is. See the example level files in `doc/example_levels` to get an idea of how these should look.

In the `.lvl` file there must be a spawn point for the player, typically represented with a 0 (but it can be anything as long as there is a texture for the player in the `.dat` file with the same number).

## Known Limitations

* No ability to pass sf::Style in window creation.
* Window resize not supported.
* No good handling of losing window focus.
* Framerate limited to 60.
* Limited player actions and keybinds.

## Planned features

* Resource manager class.
* Input mapping to allow game developers (and players) to set their own keybinds and actions.
* Artificial Intelligence.
* More scene types, including main menu, splash screen, etc.
* Audio support.
* Animation handling.
* Debug panel.
* Game window resizing to a range of resolutions.
* Handling of entity health, attacks, scores, etc.
* Better background image loading and support.
