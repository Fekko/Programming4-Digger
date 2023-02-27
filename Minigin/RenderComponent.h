#pragma once

#include "Component.h"
#include <memory>
#include <string>

namespace dae {
	class Font;
	class Texture2D;
	class RenderComponent : public Component {
	public:
		void Update([[maybe_unused]] float deltaTime) override;
		void Render() const;
		void SetText(const std::string& text);
		void SetFont(std::shared_ptr<Font> font);
		void SetTexture(const std::string& filename);

		explicit RenderComponent(GameObject* pGameObject);

	private:
		bool m_needsUpdate{};
		std::string m_text{" "};
		std::shared_ptr<Font> m_font{};
		std::shared_ptr<Texture2D> m_textTexture{};
		std::shared_ptr<Texture2D> m_texture{};
	};
}