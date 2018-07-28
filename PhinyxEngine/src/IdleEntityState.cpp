#include "../include/IdleEntityState.hpp"

PhinyxEngine::IdleEntityState::IdleEntityState() :
	BaseEntityState("Idle"), m_sourcePtr(nullptr)
{
	// We need an empty constructor for Entity... this needs fixing (TODO)
}

PhinyxEngine::IdleEntityState::IdleEntityState(LiveEntity* source) :
	BaseEntityState("Idle"), m_sourcePtr(source)
{
	enter();
}

void PhinyxEngine::IdleEntityState::enter()
{
	// m_sourcePtr->setSpriteColor(sf::Color::Yellow);
	// Set entity sprite color to a purple-ish color
	// TODO: code from our SFML AI demos, needs updating or removing
	m_sourcePtr->setSpriteColor(sf::Color(169, 20, 255));
}

void PhinyxEngine::IdleEntityState::update()
{
	// Nothing to do here, entity is idling...
}

void PhinyxEngine::IdleEntityState::exit()
{
	// Not sure what could go here, normally other states kick the entity
	// out of idle by, for example, setting their velocity
}

PhinyxEngine::BaseEntityState* PhinyxEngine::IdleEntityState::getNewState()
{
	return nullptr;
}
