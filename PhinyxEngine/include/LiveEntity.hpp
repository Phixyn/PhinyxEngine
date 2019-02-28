#ifndef LIVE_ENTITY_H
#define LIVE_ENTITY_H

#include "Entity.hpp"
#include "Logger.hpp"

namespace PhinyxEngine
{
	/// <summary>
	/// Subclass of <see cref="Entity">Entity</see> for live entities.
	/// Examples of live entities are NPCs, monsters and a player character.
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

			/// <summary>
			/// Handles events specific to the live entity.
			/// </summary>
			virtual void handleEvents() override;

			/// <summary>
			/// Updates the live entity.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			virtual void update(float deltaTime) override;

			/// <summary>
			/// Draws the live entity.
			/// </summary>
			virtual void draw() override;

			// TODO: animate?
			// TODO: getters and setters for health and other attributes
			/// <summary>
			/// Handles live entity collision.
			/// <para> Adjusts the live entity's velocity based on the given
			/// direction vector. </para>
			/// </summary>
			///
			/// <param name="direction">
			/// A SFML Vector2f containing the entity's direction.
			/// </param>
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
			/// Sets the live entity's <see cref="m_dead">m_dead</see> member
			/// variable, which specifies if the entity is dead.
			/// </summary>
			///
			/// <param name="dead">
			/// A boolean specifying if the entity is dead.
			/// </param>
			void setDead(bool dead);

			// TODO: Direction handling
			/// <summary>
			/// Gets the entity's current direction.
			/// Not yet implemented.
			/// </summary>
			///
			/// <returns>
			/// A SFML Vector2f containing the entity's direction.
			/// </returns>
			sf::Vector2f getDirection();

			/// <summary>
			/// Sets the entity's direction.
			/// Not yet implemented.
			/// </summary>
			///
			/// <param name="direction">
			/// A SFML Vector2f containing the entity's new direction.
			/// </param>
			void setDirection(sf::Vector2f direction);
		protected:
			/// <summary>
			/// Entity's health points. 0 = dead.
			/// </summary>
			int m_health;
			/// <summary>
			/// Entity's attack power. Each attack to another target entity will
			/// subtract this value from the target entity's health.
			/// </summary>
			int m_attackPower;
			/// <summary>
			/// Entity's movement speed.
			/// </summary>
			float m_speed;
			/// <summary>
			/// Entity's jump height in pixels, which is added to its Y position
			/// when it jumps.
			/// </summary>
			float m_jumpHeight;
			/// <summary>
			/// A boolean specifying if the live entity is aggressive.
			/// If a live entity is aggressive, it may attack other entities
			/// (such as the player or good/neutral NPCs).
			/// </summary>
			bool m_aggressive;
			/// <summary>
			/// A boolean specifying if the live entity is ded. X_X
			/// </summary>
			bool m_dead = false;
			/// <summary>
			/// A boolean specifying if this live entity has the ability to
			/// jump vertically.
			/// </summary>
			bool m_canJump = true;
			/// <summary>
			/// A SFML Vector2f containing the entity's velocity.
			/// </summary>
			sf::Vector2f m_velocity;
			/// <summary>
			/// A SFML Vector2f containing the entity's direction.
			/// </summary>
			// sf::Vector2f m_direction;
			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif