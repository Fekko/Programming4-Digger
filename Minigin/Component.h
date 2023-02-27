#pragma once

namespace dae {
	class GameObject;
	class Component {
	public:
		explicit Component(GameObject* pGameObject) : m_pGameObject(pGameObject) {};
		virtual ~Component() = default;
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;

		virtual void Update([[maybe_unused]] float deltaTime) = 0;
	protected:
		GameObject* const m_pGameObject{};
	};
}
