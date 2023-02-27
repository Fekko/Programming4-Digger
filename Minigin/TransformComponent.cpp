#include "TransformComponent.h"

dae::TransformComponent::TransformComponent(GameObject* pGameObject) : Component(pGameObject) {};

void dae::TransformComponent::Update([[maybe_unused]] float deltaTime) {}

void dae::TransformComponent::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}