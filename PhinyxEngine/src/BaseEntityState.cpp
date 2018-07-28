#include "../include/BaseEntityState.hpp"

PhinyxEngine::BaseEntityState::BaseEntityState(std::string stateName) : m_stateName(stateName)
{
}

std::string PhinyxEngine::BaseEntityState::getStateName()
{
	return m_stateName;
}
