#ifndef SCENE_H
#define SCENE_H

namespace PhinyxEngine {
	class Game; // forward declaration
	class Scene {
		public:
			Scene(Game &game);
			virtual void input() = 0;
			virtual void update(float dt) = 0;
			virtual void draw() = 0;
		protected:
			Game *m_game_ptr;
	};
}

#endif