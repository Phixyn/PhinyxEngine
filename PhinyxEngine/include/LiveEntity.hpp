#ifndef LIVE_ENTITY_H
#define LIVE_ENTITY_H

#include "Entity.hpp"
#include "Logger.hpp"

namespace PhinyxEngine
{
	/// <summary>
	/// Subclass of Entity for live entities. Examples of live entities are
	/// NPCs, monsters and the player character.
	/// </summary>
	class LiveEntity : public Entity
	{
		public:
			/// <summary>
			/// Default constructor taking parameters for the entity's health
			/// and attack power.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="attackPower">
			/// The power of a single attack of the live entity. Each attack
			/// to another target entity will subtract this value from the
			/// target entity's health.
			/// </param>
			LiveEntity(int health, int attackPower);

			/// <summary>
			/// Overloaded constructor taking additional parameters for the
			/// entity's speed and jump height.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="attackPower">
			/// The power of a single attack of the live entity. Each attack
			/// to another target entity will subtract this value from the
			/// target entity's health.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the live entity.
			/// </param>
			/// <param name="jumpHeight">
			/// The height of a jump action of the live entity.
			/// </param>
			LiveEntity(int health, int attackPower, float speed, float jumpHeight);

			/// <summary>
			/// Default virtual destructor for this class.
			/// Deleting a derived class object using a pointer to a base class
			/// that has a non-virtual destructor results in undefined and/or
			/// undesirable behavior. To prevent this, and to ensure that the
			/// base class' destructor is called after the derived class'
			/// destructor, the base class should have a virtual destructor.
			/// </summary>
			virtual ~LiveEntity() { }

			/// <summary> Implements Entity's handleEvents() method. </summary>
			virtual void handleEvents() override;

			/// <summary> Implements Entity's update() method. </summary>
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			virtual void update(float deltaTime) override;

			/// <summary> Implements Entity's draw() method. </summary>
			virtual void draw() override;

			// TODO: animate?
			/// <summary> Handles live entity collision. </summary>
			void onCollision(sf::Vector2f direction);

			/// <summary>
			/// Returns a value which specifies if the entity is aggressive.
			/// If a live entity is aggressive, it may attack other entities
			/// (such as the player).
			/// </summary>
			///
			/// <returns>
			/// A boolean specifying if the entity is aggressive.
			/// </returns>
			bool isAggressive() const;

			/// <summary>
			/// Returns a value which specifies if the live entity is dead.
			/// </summary>
			///
			/// <returns>
			/// A boolean specifying if the live entity is dead.
			/// </returns>
			bool isDead() const;

			/// <summary>
			/// Sets the live entity's m_dead member variable, which specifies
			/// if the entity is dead.
			/// </summary>
			///
			/// <param name="dead">
			/// A boolean specifying if the entity is dead.
			/// </param>
			void setDead(bool dead);

			// TODO: Direction handling
			/// <summary> Not yet implemented. </summary>
			/// <returns>
			/// A SFML Vector2f containing the entity's direction.
			/// </returns>
			sf::Vector2f getDirection();

			/// <summary> Not yet implemented. </summary>
			/// <param name="direction">
			/// A SFML Vector2f containing the entity's direction.
			/// </param>
			void setDirection(sf::Vector2f direction);
		protected:
			int m_health;
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