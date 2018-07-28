#ifndef ENEMY_MONSTER_H
#define ENEMY_MONSTER_H

#include "LiveEntity.hpp"

namespace PhinyxEngine
{
	/// <summary> Subclass of LiveEntity for enemy monsters. </summary>
	class EnemyMonster : public LiveEntity
	{
		public:
			/// <summary>
			/// Default constructor taking parameters for the monster's health
			/// and attack power.
			/// </summary>
			///
			/// <param name="health">The health points of the monster.</param>
			/// <param name="attackPower">The power of a single attack of the
			/// monster. Each attack to another target entity will subtract
			/// this value from the target entity's health.</param>
			EnemyMonster(int health, int attackPower);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~EnemyMonster() { }

			/// <summary>
			/// Not yet implemented. Handles events pertaining to the
			/// tile entity.
			/// </summary>
			///
			/// <param name="sfEvent">
			/// A SFML event (e.g. generated user input) object.
			/// </param>
			void handleEvents(sf::Event sfEvent) override;

			/// <summary>
			/// Not yet implemented. Updates the tile entity.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			void update(float deltaTime) override;

			/// <summary>
			/// Not yet implemented. Draws the tile entity.
			/// </summary>
			void draw() override;
	};
}

#endif