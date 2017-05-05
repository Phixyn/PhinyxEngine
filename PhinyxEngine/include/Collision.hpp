#ifndef COLLISION_H
#define COLLISION_H

#include "Logger.hpp"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine
{
	/// <summary>
	/// Class for handling and solving collisions between entities.
	/// </summary>
	class Collision
	{
		public:
			/// <summary> Default constructor. </summary>
			///
			/// <param name="rect"> Reference to a SFML RectangleShape
			/// object. </param>
			Collision(sf::RectangleShape &rect);

			/// <summary> Moves a SFML RectangleShape by calling its move()
			/// method with the X and Y offsets passed in the parameters.
			/// </summary>
			///
			/// <param name="dirX"> X axis offset used for moving the
			/// rectangle. </param>
			/// <param name="dirY"> Y axis offset used for moving the
			/// rectangle. </param>
			void moveRect(float dirX, float dirY);

			/// <summary> Performs AABB collision detection and collision
			/// solving. </summary>
			///
			/// <param name="collider"> An instance of Collision of the body that is
			/// colliding with this body. </param>
			/// <param name="direction"> A SFML Vector2f to which the new
			/// direction of the colliding body will be written to. </param>
			/// <param name="force"> The force that the colliding body
			/// exercises on the collider. Forces above 0.0f will cause the
			/// colliding body to move the collider. Forces below 0.0f will
			/// cause the collider to move the colliding body, exercising a
			/// knockback effect on the colliding body.
			/// <para> For example, a force of 0.0f could be used when a player
			/// is colliding with a wall, as the player should not be able to
			/// move through walls. </para> </param>
			///
			/// <returns> Returns a boolean indicating if the two bodies have
			/// collided. </returns>
			bool handleCollision(Collision &collider, sf::Vector2f &direction, float force);

			/// <summary> Returns the position of this body. </summary>
			/// <returns> SFML Vector2f object containing this body's
			/// postion. </returns>
			sf::Vector2f getPosition();

			/// <summary> Returns the halfsize of this body. </summary>
			/// <returns> SFML Vector2f object containing this body's
			/// size divided by two. </returns>
			sf::Vector2f getHalfSize();
		private:
			sf::RectangleShape &m_rect;
			Logger m_logger;
	};
}

#endif