#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

#include "AudioComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "InputComponent.h"
#include "FpsComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update([[maybe_unused]] float deltaTime) {
	if (m_pAudioComponent)		m_pAudioComponent->Update(deltaTime);
	if (m_pPhysicsComponent)	m_pPhysicsComponent->Update(deltaTime);
	if (m_pRenderComponent)		m_pRenderComponent->Update(deltaTime);
	if (m_pTransformComponent)	m_pTransformComponent->Update(deltaTime);
	if (m_pInputComponent)		m_pInputComponent->Update(deltaTime);
	if (m_pFpsComponent)		m_pFpsComponent->Update(deltaTime);
}

void dae::GameObject::Render() const
{
	if (m_pRenderComponent) m_pRenderComponent->Render();
	if (m_pFpsComponent)	m_pFpsComponent->Render();
}

void dae::GameObject::Destroy() {
	isAlive = false;
}

bool dae::GameObject::IsAlive() const {
	return isAlive;
}
