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
			/// Overloaded constructor taking parameters for the entity's health,
			/// size and position.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the live entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			LiveEntity(int health, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking parameters for the entity's health,
			/// attack power, size and position.
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
			/// <param name="size">
			/// A SFML Vector2f containing the live entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			LiveEntity(int health, int attackPower, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking parameters for the entity's health,
			/// size, position and speed.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the live entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the live entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			LiveEntity(int health, float speed, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking parameters for the entity's health,
			/// attack power, speed, size and position.
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
			/// <param name="size">
			/// A SFML Vector2f containing the live entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			LiveEntity(int health, int attackPower, float speed, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking parameters for the entity's health,
			/// attack power, speed, jump height, size and position.
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
			/// <param name="size">
			/// A SFML Vector2f containing the live entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			LiveEntity(int health, int attackPower, float speed, float jumpHeight, sf::Vector2f size, sf::Vector2f position);

			// TODO Overloaded constructors with:
			//  * velocity
			//  * direction?
			//  * aggressive?

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
			///
			/// <param name="sfEvent">
			/// A SFML event (e.g. generated user input) object.
			/// </param>
			virtual void handleEvents(sf::Event sfEvent) override;

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

			/// <summary>
			/// Sets the live entity's health points.
			/// </summary>
			///
			/// <param name="health">
			/// An integer specifying the entity's new health points.
			/// </param>
			void setHealth(int health);
			/// <summary>
			/// Returns the entity's current health points.
			/// </summary>
			///
			/// <returns>
			/// An integer containing the entity's current health points.
			/// </returns>
			int getHealth();
			/// <summary>
			/// Sets the entity's speed.
			/// </summary>
			///
			/// <param name="speed">
			/// Float specifying the entity's speed.
			/// </param>
			void setSpeed(float speed);
			/// <summary>
			/// Sets the entity's maximum speed.
			/// </summary>
			///
			/// <param name="maxSpeed">
			/// Float specifying the entity's maximum speed.
			/// </param>
			void setMaxSpeed(float maxSpeed);
			/// <summary>
			/// Returns the entity's current speed.
			/// </summary>
			///
			/// <returns>
			/// Float specifying the entity's speed.
			/// </returns>
			float getSpeed();
			/// <summary>
			/// Returns the entity's maximum speed.
			/// </summary>
			///
			/// <returns>
			/// Float specifying the entity's maximum speed.
			/// </returns>
			float getMaxSpeed();

			// TODO: animate?
			/// <summary>
			/// Handles live entity collision.
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
			/// Sets the live entity's m_dead member variable, which specifies
			/// if the entity is dead.
			/// </summary>
			///
			/// <param name="dead">
			/// A boolean specifying if the entity is dead.
			/// </param>
			void setDead(bool dead);

			/* The following two methods are only used in the flee and seek
			 * entity classes, and are straight from our SFML Game AI demos
			 * project. They shouldn't be used in this project right now
			 * and will probably need refactoring to fit the context of this
			 * game engine. Any attempts to use these methods or the flee and
			 * seek entity state classes will most likely end up badly.
			 */
			/// <summary>
			/// Gets the entity's current velocity vector.
			/// </summary>
			///
			/// <returns>
			/// A SFML Vector2f containing the entity's velocity.
			/// </returns>
			sf::Vector2f getVelocity();
			/// <summary>
			/// Sets the entity's velocity vector.
			/// </summary>
			/// <param name="velocity">
			/// A SFML Vector2f containing the entity's new velocity.
			/// </param>
			void setVelocity(sf::Vector2f velocity);

			// TODO: Direction handling
			/// <summary>
			/// Not yet implemented.
			/// </summary>
			///
			/// <returns>
			/// A SFML Vector2f containing the entity's direction.
			/// </returns>
			sf::Vector2f getDirection();

			/// <summary>
			/// Not yet implemented.
			/// </summary>
			///
			/// <param name="direction">
			/// A SFML Vector2f containing the entity's direction.
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
			/// Entity's maximum movement speed.
			/// </summary>
			float m_maxSpeed;
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
			bool m_dead;
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