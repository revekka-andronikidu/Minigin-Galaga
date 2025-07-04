#pragma once
#include <memory>
#include <string>
#include <iostream>

namespace dae
{
	class GameObject;
	class BaseComponent
	{
		GameObject* const m_pOwner;
	public:
		virtual ~BaseComponent() = default;
		BaseComponent(const BaseComponent&) = delete;
		BaseComponent(BaseComponent&&) noexcept = delete;
		BaseComponent& operator=(const BaseComponent&) = delete;
		BaseComponent& operator=(BaseComponent&&) noexcept = delete;

		virtual void Update() = 0;
		virtual void FixedUpdate(const float fixedTimeStep) = 0;

		//virtual void Render() const = 0; //not every component needs to be rendered
		//virtual void LateUpdate() = 0; //implement later

		virtual void MarkForRemoval() { m_IsDeadComponent = true; };
		bool IsMarkedForRemoval() const { return m_IsDeadComponent; };
		GameObject* GetOwner() const { return m_pOwner; };

	protected:
		
		explicit BaseComponent(GameObject* pOwner) : m_pOwner{ pOwner } {}; // protected constructor
		

	private:
		bool m_IsDeadComponent{ false };

	};
}

