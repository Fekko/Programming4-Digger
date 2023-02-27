#pragma once

#include "Component.h"

namespace dae {
	class AudioComponent final : public Component {
	public:
		void Update([[maybe_unused]] float deltaTime) override;

		explicit AudioComponent(GameObject* pGameObject);
	};
}
