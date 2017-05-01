#ifndef TILE_ENTITY_H
#define TILE_ENTITY_H

#include "Entity.h"

namespace PhinyxEngine {
	class TileEntity : public Entity {
		public:
			TileEntity(sf::RectangleShape rect);
			void handleEvents() override;
			void update(float deltaTime) override;
			void draw() override;
		private:
			float force;
	};
}

#endif