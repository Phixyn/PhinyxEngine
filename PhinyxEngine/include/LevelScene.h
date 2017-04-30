#ifndef LEVEL_SCENE_H
#define LEVEL_SCENE_H

#include "Scene.h"
#include <string>

namespace PhinyxEngine {
	class LevelScene : public Scene {
		public:
			LevelScene(Game &game, std::string levelFile, std::string dataFile);
			void input() override;
			void update(float dt) override;
			void draw() override;
		private:
			std::string m_levelFile;
			std::string m_dataFile;
	};
}

#endif
