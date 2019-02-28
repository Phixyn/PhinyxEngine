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
			/// Default constructor taking an argument for the tile's rect. 
			/// </summary>
			///
			/// <param name="rect">
			/// A SFML RectangleShape used to specify a tile.
			/// </param>
			TileEntity(sf::RectangleShape rect);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~TileEntity() { }

			/// <summary>
			/// Handles events specific to the tile entity.
			/// </summary>
			void handleEvents() override;

			/// <summary>
			/// Updates the tile entity.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			void update(float deltaTime) override;

			/// <summary>
			/// Draws the tile entity.
			/// </summary>
			void draw() override;
		private:
			/// <summary>
			/// <para> Force of this tile entity. </para>
			/// <para> 0 = solid and can't be moved. </para>
			///
			/// <para> TODO: Negative values should allow the player to move it by
			/// m_force per second (?) (with an onCollision method like
			/// in LiveEntity). </para>
			///
			/// <para> TODO: Add getters and setters for this. And update/draw
			/// should take force into consideration (can make tasks for this).
			/// </para>
			/// </summary>
			float m_force;
	};
}

#endif