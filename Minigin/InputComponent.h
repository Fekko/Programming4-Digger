#pragma once
#include "Component.h"

namespace dae {
	class InputComponent final : public Component {
	public:
		void Update([[maybe_unused]] float deltaTime) override;

		explicit InputComponent(GameObject* pGameObject);
	};
}