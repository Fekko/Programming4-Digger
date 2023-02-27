#pragma once
#include "Component.h"

namespace dae {
	class PhysicsComponent final : public Component {
	public:
		void Update([[maybe_unused]] float deltaTime) override;

		explicit PhysicsComponent(GameObject* pGameObject);
	};
}