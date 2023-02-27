#include "FpsComponent.h"
#include "RenderComponent.h"
#include "GameObject.h"

void dae::FpsComponent::Update([[maybe_unused]] float deltaTime) 
{
	passedTime += deltaTime;
	if (passedTime >= 1.f) {
		m_pGameObject->GetComponent<RenderComponent>()->SetText(std::to_string(frameCounter));
		frameCounter = 0;
		passedTime = 0;
	}
}

void dae::FpsComponent::Render() {
	++frameCounter;
}

dae::FpsComponent::FpsComponent(GameObject* pGameObject) : Component(pGameObject)
{}