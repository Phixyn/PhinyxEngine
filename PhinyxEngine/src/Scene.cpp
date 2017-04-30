#include "../include/Scene.h"

// Set m_game_ptr to argumeng &game passed (we could also have it in the
// method body, but this is shorter
PhinyxEngine::Scene::Scene(Game &game) : m_game_ptr(&game) {

}