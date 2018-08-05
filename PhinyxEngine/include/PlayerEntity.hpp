#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

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
			/// The health points of the player entity.
			/// </param>
			/// <param name="attackPower">
			/// The power of a single attack of the player entity. Each attack
			/// to another target entity will subtract this value from the
			/// target entity's health.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the player entity.
			/// </param>
			/// <param name="jumpHeight">
			/// The height of a jump action of the player entity.
			/// </param>
			PlayerEntity(int health, int attackPower, float speed, float jumpHeight);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~PlayerEntity() { }

			/// <summary>
			/// Handles events specific to the player entity.
			/// </summary>
			void handleEvents() override;

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
	};
}

#endif