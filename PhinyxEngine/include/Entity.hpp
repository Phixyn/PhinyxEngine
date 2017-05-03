#ifndef ENTITY_H
#define ENTITY_H

#include "Collision.hpp"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine
{
	/// <summary> Placeholder class documentation </summary>
	class Entity
	{
		public:
			/// <summary> Default constructor. </summary>
			Entity();

			/// <summary>
			/// Pure virtual method to handle events of the Entity.
			/// </summary>
			virtual void handleEvents() = 0;

			/// <summary>
			/// Pure virtual method to update the scene.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			virtual void update(float deltaTime) = 0;

			/// <summary>
			/// Pure virtual method for drawing the scene.
			/// </summary>
			virtual void draw() = 0;

			/// <summary>
			/// Sets the texture for the entity.
			/// </summary>
			void setTexture(sf::Texture *texture);

			/// <summary>
			/// Returns a new instance of Collision for this entity, which
			/// can be used to handle and solve collisions between this
			/// entity and other entities in the game.
			/// </summary>
			///
			/// <returns>
			/// A new instance of Collision with the Entity's rectangle.
			/// </returns>
			Collision getCollision();

			float m_rectWidth;
			float m_rectHeight;
			sf::RectangleShape m_rect;
			Collision m_collision; // TODO: make this private?
	};
}

#endif