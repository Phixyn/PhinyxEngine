#ifndef SCENE_H
#define SCENE_H

namespace PhinyxEngine
{
	// Forward declaration for the Game class.
	class Game;
	/// <summary>
	/// A class for scenes and scene management. Scenes can be anything
	/// from levels, to main menu screens.
	/// </summary>
	class Scene
	{
		public:
			/// <summary> Default constructor. </summary>
			///
			/// <param name="game">
			/// A pointer to an instance of the Game class.
			/// </param>
			Scene(Game &game);

			/// <summary>
			/// Default virtual destructor for this class.
			/// Deleting a derived class object using a pointer to a base class
			/// that has a non-virtual destructor results in undefined and/or
			/// undesirable behavior. To prevent this, and to ensure that the
			/// base class' destructor is called after the derived class'
			/// destructor, the base class should have a virtual destructor.
			/// </summary>
			virtual ~Scene() { }

			/// <summary>
			/// Pure virtual method to handle events in the scene.
			/// Pure virtual methods must always be overriden in derived
			/// classes.
			/// </summary>
			virtual void handleEvents() = 0;

			/// <summary> Pure virtual method to update the scene. </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			virtual void update(float deltaTime) = 0;

			/// <summary> Pure virtual method for drawing the scene. </summary>
			virtual void draw() = 0;
		protected:
			/// <summary> Pointer to an instance of the Game class. </summary>
			Game *m_game_ptr;
	};
}

#endif