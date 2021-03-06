#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "LiveEntity.hpp"

namespace PhinyxEngine
{
	/// <summary>
	/// Subclass of LiveEntity for the player character.
	/// </summary>
	class PlayerEntity : public LiveEntity
	{
		public:
			/// <summary>
			/// Default constructor.
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
			/// Default class destructor.
			/// </summary>
			~PlayerEntity() { }

			// void handleEvents() override;

			/// <summary> Overrides Entity's update() method. </summary>
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			void update(float deltaTime) override;

			/// <summary> Overrides Entity's draw() method. </summary>
			void draw() override;
	};
}

#endif