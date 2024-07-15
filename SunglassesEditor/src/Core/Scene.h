#pragma once
#include <vector>
#include <Entity.h>

class Scene
{
public:
	Scene();
	~Scene() = default;

	void Initialize();
	
	void Update();
	void Draw();


	void Add(std::shared_ptr<Entity> entity)
	{
		m_sceneEntities.push_back(entity);
	}

private:
	Camera3D m_sceneCamera;
	std::vector<std::shared_ptr<Entity>>m_sceneEntities;
};

