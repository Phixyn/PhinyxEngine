#include "../include/LiveEntity.h"

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower) :
	Entity(), m_acceleration(0.0f, 0.0f)
{
	m_health = health;
	m_attackPower = attackPower;
}

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower, float speed) :
	Entity(), m_acceleration(0.0f, 0.0f)
{
	m_health = health;
	m_attackPower = attackPower;
	m_speed = speed;
}

void PhinyxEngine::LiveEntity::handleEvents() {
	// TODO
}

void PhinyxEngine::LiveEntity::update(float deltaTime) {
	// TODO
}

void PhinyxEngine::LiveEntity::draw() {
	// TODO
}

bool PhinyxEngine::LiveEntity::isAggressive() {
	return m_aggressive;
}

bool PhinyxEngine::LiveEntity::isDead() {
	return m_dead;
}

void PhinyxEngine::LiveEntity::setDead(bool dead) {
	m_dead = dead;
}

float PhinyxEngine::LiveEntity::getDirection() {
	return m_direction;
}

void PhinyxEngine::LiveEntity::setDirection(float direction) {
	m_direction = direction;
}
