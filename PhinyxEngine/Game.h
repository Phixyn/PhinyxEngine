#ifndef GAME_H
#define GAME_H

#include "Window.h"

namespace PhinyxEngine {
	class Game {
		public:
			Game();
			void mainLoop();

			Window gameWindow;
		private:
	};
}

#endif