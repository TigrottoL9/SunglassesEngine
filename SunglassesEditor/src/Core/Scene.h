#pragma once
#include <vector>
#include <Entity.h>

#define CreateScene() std::make_shared<Scene>()

class Scene
{
public:

	Scene();
	~Scene() = default;

	void Initialize();
	
	void Update();
	void Draw();
	void Add(std::shared_ptr<Entity> entity);

	void SetMainCamera(std::shared_ptr<Camera3D> camera);
private:
	std::shared_ptr<Camera3D> m_mainCamera;

	std::vector<std::shared_ptr<Entity>>m_sceneEntities;
};

typedef std::shared_ptr<Scene> ScenePtr;