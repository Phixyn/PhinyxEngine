#ifndef ENTITY_H
#define ENTITY_H

namespace PhinyxEngine {
	class Entity {
		public:
			Entity();
			virtual void input() = 0;
			virtual void update(float dt) = 0;
			virtual void draw() = 0;
	};
}

#endif