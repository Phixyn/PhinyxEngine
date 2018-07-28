#include "../include/DeadEntityState.hpp"

PhinyxEngine::DeadEntityState::DeadEntityState() : BaseEntityState("Dead")
{
}

void PhinyxEngine::DeadEntityState::enter()
{
}

void PhinyxEngine::DeadEntityState::update()
{
}

void PhinyxEngine::DeadEntityState::exit()
{
}

PhinyxEngine::BaseEntityState* PhinyxEngine::DeadEntityState::getNewState()
{
	return nullptr;
}
