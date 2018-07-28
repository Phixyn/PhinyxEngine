#ifndef TILE_ENTITY_H
#define TILE_ENTITY_H

#include "Entity.hpp"

namespace PhinyxEngine
{
	/// <summary>
	/// Subclass of <see cref="Entity">Entity</see> for tile entities. Tiles can
	/// be anything from flooring and wall rectangle shapes, to traps or items
	/// that can be picked up by the player.
	/// </summary>
	class TileEntity : public Entity
	{
		public:
			/// <summary>
			/// Default constructor. Takes a SFML RectangleShape
			/// for the tile as a parameter.
			/// </summary>
			TileEntity(sf::RectangleShape rect);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~TileEntity() { }

			/// <summary>
			/// Not yet implemented. Handles events specific to the
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
		private:
			/// <summary>
			/// Force of this tile entity.
			/// 0 = solid and can't be moved
			/// TODO:  Positive values should allow the player to move it by
			/// m_force per second (?) (or should it be negative values that
			/// allow this?)
			/// TODO: Add getters and setters for this. And update/draw should
			/// take force into consideration (can make tasks for this)
			/// </summary>
			float m_force;
	};
}

#endif