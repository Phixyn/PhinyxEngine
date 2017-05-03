#ifndef TILE_ENTITY_H
#define TILE_ENTITY_H

#include "Entity.hpp"

namespace PhinyxEngine
{
	/// <summary>
	/// Subclass of Entity for tile entities. Tiles can be anything from
	/// flooring and wall rectangle shapes, to traps or items that can be
	/// picked up by the player.
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
			/// Not yet implemented. Handles events pertaining to the
			/// tile entity.
			/// </summary>
			void handleEvents() override;

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
			float m_force;
	};
}

#endif