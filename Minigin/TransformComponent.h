#pragma once

#include <glm/glm.hpp>
#include "Component.h"


namespace dae {
	class TransformComponent final : public Component {
	public:
		void Update([[maybe_unused]] float deltaTime);
		const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(const float x, const float y, const float z = 0);

		explicit TransformComponent(GameObject* pGameObject);

	private:
		glm::vec3 m_position{};
	};
}