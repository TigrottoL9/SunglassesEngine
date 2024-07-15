#include "Scene.h"

Scene::Scene() : m_sceneCamera(), m_sceneEntities()
{
	m_sceneCamera.position = Vector3{ 10.0f, 10.0f, 10.0f };
	m_sceneCamera.target = Vector3{ 0.0f, .0f, 0.0f };
	m_sceneCamera.up = Vector3{ 0.0f, 1.0f, 0.0f };

	m_sceneCamera.projection = CAMERA_PERSPECTIVE;
	m_sceneCamera.fovy = 60;

}

void Scene::Initialize()
{
	for (std::shared_ptr<Entity>& entity : m_sceneEntities)
	{
		entity->Initialize();
	}
}

void Scene::Update()
{
	for (std::shared_ptr<Entity>& entity : m_sceneEntities)
	{
		entity->Update();
	}
}

void Scene::Draw()
{
	BeginMode3D(m_sceneCamera);

	for (std::shared_ptr<Entity>& entity : m_sceneEntities)
	{
		entity->Draw();
	}

	EndMode3D();
}
