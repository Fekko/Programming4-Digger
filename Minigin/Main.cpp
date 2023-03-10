#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "GameObject.h"

#include "AudioComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "InputComponent.h"
#include "FpsComponent.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TransformComponent>();
	go->AddComponent<dae::RenderComponent>();
	go->GetComponent<dae::RenderComponent>()->SetTexture("background.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TransformComponent>();
	go->GetComponent<dae::TransformComponent>()->SetPosition(216, 180);
	go->AddComponent<dae::RenderComponent>();	
	go->GetComponent<dae::RenderComponent>()->SetTexture("logo.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	auto font1 = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	go->AddComponent<dae::TransformComponent>();
	go->GetComponent<dae::TransformComponent>()->SetPosition(80, 20);
	go->AddComponent<dae::RenderComponent>();
	go->GetComponent<dae::RenderComponent>()->SetFont(font1);
	go->GetComponent<dae::RenderComponent>()->SetText("Programming 4 Assignment");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	auto font2 = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 18);
	go->AddComponent<dae::TransformComponent>();
	go->GetComponent<dae::TransformComponent>()->SetPosition(10, 10);
	go->AddComponent<dae::RenderComponent>();
	go->GetComponent<dae::RenderComponent>()->SetFont(font2);
	go->AddComponent<dae::FpsComponent>();
	scene.Add(go);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}