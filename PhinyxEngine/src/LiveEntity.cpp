#include "../include/LiveEntity.h"

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower) : Entity() {
	m_health = health;
	m_attackPower = attackPower;
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