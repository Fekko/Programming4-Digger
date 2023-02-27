#include "RenderComponent.h"

#include "ResourceManager.h"
#include <stdexcept>
#include <SDL_ttf.h>
#include "GameObject.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"
#include "TransformComponent.h"


dae::RenderComponent::RenderComponent(GameObject* pGameObject) : Component(pGameObject) {};

void dae::RenderComponent::Update([[maybe_unused]] float deltaTime)
{
	if (m_needsUpdate)
	{
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_textTexture = std::make_shared<Texture2D>(texture);
		m_needsUpdate = false;
	}
}

void dae::RenderComponent::Render() const
{
	const auto transformComponent = m_pGameObject->GetComponent<TransformComponent>();
	if (transformComponent)
	{
		const auto& pos = transformComponent->GetPosition();
		if (m_textTexture) {
			Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y);
		}
		if (m_texture) {
			Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
		}
	}
}

void dae::RenderComponent::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

// This implementation uses the "dirty flag" pattern
void dae::RenderComponent::SetText(const std::string& text)
{
	m_text = text;
	m_needsUpdate = true;
}

void dae::RenderComponent::SetFont(std::shared_ptr<Font> font)
{
	m_font = font;
	m_needsUpdate = true;
}