#include "../include/LiveEntity.h"

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower) : Entity() {
	m_health = health;
	m_attackPower = attackPower;
}

void PhinyxEngine::LiveEntity::input() {
	// TODO
}

void PhinyxEngine::LiveEntity::update(float dt) {
	// TODO
}

void PhinyxEngine::LiveEntity::draw() {
	// TODO
}

bool PhinyxEngine::LiveEntity::isAggressive() {
	return m_aggressive;
}