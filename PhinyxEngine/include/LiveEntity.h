#ifndef LIVE_ENTITY_H
#define LIVE_ENTITY_H

#include "Entity.h"
#include "Logger.h"

namespace PhinyxEngine {
	class LiveEntity : public Entity {
		public:
			/// <summary>
			/// Default constructor taking parameters for the entity's health
			/// and attack power.
			/// </summary>
			///
			/// <param name="health">The health points of the live entity.</param>
			/// <param name="attackPower">The power of a single attack of the
			/// live entity. Each attack to another target entity will subtract
			/// this value from the target entity's health.</param>
			LiveEntity(int health, int attackPower);

			/// <summary>
			/// Overloaded constructor taking additional parameters for the
			/// entity's speed and jump height.
			/// </summary>
			///
			/// <param name="health">The health points of the live entity.</param>
			/// <param name="attackPower">The power of a single attack of the
			/// live entity. Each attack to another target entity will subtract
			/// this value from the target entity's health.</param>
			/// <param name="speed">The movement speed of the live entity.</param>
			/// <param name="jumpHeight">The height of a jump action of the
			/// live entity.</param>
			LiveEntity(int health, int attackPower, float speed, float jumpHeight);

			/// <summary> Implements Entity's handleEvents() method. </summary>
			void handleEvents() override;
			/// <summary> Implements Entity's update() method. </summary>
			void update(float deltaTime) override;
			/// <summary> Implements Entity's draw() method. </summary>
			void draw() override;

			// TODO: animate?
			/// <summary> Handles live entity collision. </summary>
			void onCollision(sf::Vector2f direction);

			/// <summary> Returns a value which specifies if the entity is aggressive.
			/// If a live entity is aggressive, it may attack other entities
			/// (such as the player). </summary>
			///
			/// <returns> A boolean specifying if the entity is aggressive. </returns>
			bool isAggressive();
			/// <summary> Returns a value which specifies if the live entity is
			/// dead. </summary>
			///
			/// <returns> A boolean specifying if the live entity is dead. </returns>
			bool isDead();
			/// <summary> Sets the live entity's m_dead member variable, which
			/// specifies if the entity is dead. </summary>
			///
			/// <param name="dead"> A boolean specifying if the entity is dead. </param>
			void setDead(bool dead);

			// TODO: Direction handling
			/// <summary> Not yet implemented. </summary>
			sf::Vector2f getDirection();
			/// <summary> Not yet implemented. </summary>
			void setDirection(sf::Vector2f direction);
		protected:
			int m_health;
			/// Test comment about attack power
			int m_attackPower;
			float m_speed;
			float m_jumpHeight;
			bool m_aggressive;
			bool m_dead;
			bool m_canJump = true;
			sf::Vector2f m_velocity;
			// sf::Vector2f m_direction;
			Logger m_logger;
	};
}

#endif