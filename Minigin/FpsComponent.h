#pragma once

#include "Component.h"

namespace dae {
	class FpsComponent final : public Component {
	public:
		void Update([[maybe_unused]] float deltaTime) override;
		void Render();

		explicit FpsComponent(GameObject* pGameObject);
	private:
		float passedTime{};
		int frameCounter{};
	};
}
