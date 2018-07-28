#ifndef PLAYER_H
#define PLAYER_H

#include "LiveEntity.hpp"

namespace PhinyxEngine
{
	/// <summary>
	/// Subclass of <see cref="LiveEntity">LiveEntity</see> for the player
	/// character entity.
	/// </summary>
	class PlayerEntity : public LiveEntity
	{
		public:
			/// <summary>
			/// Default constructor taking parameters for the player's health,
			/// attack power, speed and jump height.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the player.
			/// </param>
			/// <param name="attackPower">
			/// The power of a single attack of the player. Each attack
			/// to another target entity will subtract this value from the
			/// target entity's health.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the player.
			/// </param>
			/// <param name="jumpHeight">
			/// The height of a jump action of the player.
			/// </param>
			PlayerEntity(int health, int attackPower, float speed, float jumpHeight);

			/// <summary>
			/// Overloaded constructor taking parameters for the player's health,
			/// size and position. (TODO: make this default and the above an
			/// overloaded constructor)
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the player entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the player entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the player's position on the
			/// game scene.
			/// </param>
			PlayerEntity(int health, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking parameters for the player's health,
			/// attack power, size and position.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the player entity.
			/// </param>
			/// <param name="attackPower">
			/// The power of a single attack of the player. Each attack
			/// to another target entity will subtract this value from the
			/// target entity's health.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the player entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the player's position on the
			/// game scene.
			/// </param>
			PlayerEntity(int health, int attackPower, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking parameters for the player's health,
			/// speed, size and position.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the player entity.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the player entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the player entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the player's position on the
			/// game scene.
			/// </param>
			PlayerEntity(int health, float speed, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking parameters for the player's health,
			/// attack power, speed, size and position.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the player entity.
			/// </param>
			/// <param name="attackPower">
			/// The power of a single attack of the player. Each attack
			/// to another target entity will subtract this value from the
			/// target entity's health.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the player entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the player entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the player's position on the
			/// game scene.
			/// </param>
			PlayerEntity(int health, int attackPower, float speed, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Overloaded constructor taking parameters for the player's health,
			/// attack power, speed, jump height, size and position.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the player entity.
			/// </param>
			/// <param name="attackPower">
			/// The power of a single attack of the player. Each attack
			/// to another target entity will subtract this value from the
			/// target entity's health.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the player entity.
			/// </param>
			/// <param name="jumpHeight">
			/// The height of a jump action of the player.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the player entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the player's position on the
			/// game scene.
			/// </param>
			PlayerEntity(int health, int attackPower, float speed, float jumpHeight, sf::Vector2f size, sf::Vector2f position);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~PlayerEntity() { }

			/// <summary>
			/// Handles events specific to the player entity.
			/// </summary>
			///
			/// <param name="sfEvent">
			/// A SFML event (e.g. generated user input) object.
			/// </param>
			void handleEvents(sf::Event sfEvent) override;

			/// <summary>
			/// Updates the player entity.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			void update(float deltaTime) override;

			/// <summary>
			/// Draws the player entity.
			/// </summary>
			void draw() override;

		protected:
			/// <summary>
			/// File path and name of the image containing the player entity's
			/// texture.
			/// </summary>
			// TODO: update this
			const std::string ENTITY_TEXTURE = "assets/boid.png";
	};
}

#endif