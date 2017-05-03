#include "../include/Scene.hpp"

/// <summary> Sets m_game_ptr to the reference of Game in the
/// parameter. </summary>
PhinyxEngine::Scene::Scene(Game &game) : m_game_ptr(&game)
{

}