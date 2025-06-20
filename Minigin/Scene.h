#pragma once
#include "SceneManager.h"

namespace dae
{
	class GameObject;
	class Scene final
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(std::shared_ptr<GameObject> object);
		void Remove(std::shared_ptr<GameObject> object);
		void RemoveAll();

		void Update();
		void FixedUpdate(const float fixed_time_step);
		void LateUpdate();
		void Render() const;
		std::string GetSceneName() { return m_name; };
		std::vector<GameObject*> GetObjectsInScene() const //copy of game objects in the scene 
		{
			std::vector<GameObject*> objects{};
			objects.reserve(m_objects.size());
			for (const auto& object : m_objects)
			{
				objects.emplace_back(object.get());
			}
			return objects;
		};

		std::vector<GameObject*> GetObjectsWithTag(std::string tag) const; //copy of game objects in the scene 
		

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);
		void DestroyObjects();
		std::string m_name;
		std::vector < std::shared_ptr<GameObject>> m_objects{};

		static unsigned int m_idCounter; 
	};

}
