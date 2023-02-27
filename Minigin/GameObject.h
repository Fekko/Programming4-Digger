#pragma once
#include <memory>
#include <vector>

namespace dae
{
	class AudioComponent;
	class PhysicsComponent;
	class RenderComponent;
	class TransformComponent;
	class InputComponent;
	class FpsComponent;
	class GameObject final
	{
	public:
		virtual void Update([[maybe_unused]] float deltaTime);
		virtual void Render() const;

		template <typename T>
		void AddComponent() {
			if constexpr (std::is_same_v<T, AudioComponent>) {
				m_pAudioComponent = std::make_unique<T>(this);
			}
			if constexpr (std::is_same_v<T, PhysicsComponent>) {
				m_pPhysicsComponent = std::make_unique<T>(this);
			}
			if constexpr (std::is_same_v<T, RenderComponent>) {
				m_pRenderComponent = std::make_unique<T>(this);
			}
			if constexpr (std::is_same_v<T, TransformComponent>) {
				m_pTransformComponent = std::make_unique<T>(this);
			}
			if constexpr (std::is_same_v<T, InputComponent>) {
				m_pInputComponent = std::make_unique<T>(this);
			}
			if constexpr (std::is_same_v<T, FpsComponent>) {
				m_pFpsComponent = std::make_unique<T>(this);
			}
		}

		template <typename T>
		T* GetComponent() const {
			if constexpr (std::is_same_v<T, AudioComponent>) {
				return m_pAudioComponent.get();
			}
			if constexpr (std::is_same_v<T, PhysicsComponent>) {
				return m_pPhysicsComponent.get();
			}
			if constexpr (std::is_same_v<T, RenderComponent>) {
				return m_pRenderComponent.get();
			}
			if constexpr (std::is_same_v<T, TransformComponent>) {
				return m_pTransformComponent.get();
			}
			if constexpr (std::is_same_v<T, InputComponent>) {
				return m_pInputComponent.get();
			}
			if constexpr (std::is_same_v<T, FpsComponent>) {
				return m_pFpsComponent.get();
			}
		}

		template <typename T>
		void RemoveComponent() {
			if constexpr (std::is_same_v<T, AudioComponent>) {
				m_pAudioComponent.reset();
			}
			if constexpr (std::is_same_v<T, PhysicsComponent>) {
				m_pPhysicsComponent.reset();
			}
			if constexpr (std::is_same_v<T, RenderComponent>) {
				m_pRenderComponent.reset();
			}
			if constexpr (std::is_same_v<T, TransformComponent>) {
				m_pTransformComponent.reset();
			}
			if constexpr (std::is_same_v<T, InputComponent>) {
				m_pInputComponent.reset();
			}
			if constexpr (std::is_same_v<T, FpsComponent>) {
				m_pFpsComponent.reset();
			}
		}

		template <typename T>
		bool ContainsComponent() {
			return GetComponent<T>();
		}

		void Destroy();
		bool IsAlive() const;

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		std::unique_ptr<AudioComponent>		m_pAudioComponent{};
		std::unique_ptr<PhysicsComponent>	m_pPhysicsComponent{};
		std::unique_ptr<RenderComponent>	m_pRenderComponent{};
		std::unique_ptr<TransformComponent> m_pTransformComponent{};
		std::unique_ptr<InputComponent>		m_pInputComponent{};
		std::unique_ptr<FpsComponent>		m_pFpsComponent{};

		bool isAlive{ true };
	};
}
