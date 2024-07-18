#include "Scene.h"
#include <iostream>

#include "../../raylib-master/src/raymath.h"

Scene::Scene() : m_mainCamera(nullptr), m_sceneEntities()
{
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
	//Se non c'è camera non disegnare nada
	if (m_mainCamera == nullptr) 
	{
		ClearBackground(DARKGRAY);
		DrawText("No Main Camera available!!", GetScreenWidth()/2-250, GetScreenHeight()/2 - 50, 40, WHITE);
		return;
	}

	//Render Pass
	BeginMode3D(*m_mainCamera);
	DrawGrid(100, 1);
	DrawLine3D(Vector3Zero(), Vector3{ 100, 0, 0 }, RED);
	DrawLine3D(Vector3Zero(), Vector3{ 0, 100, 0 }, GREEN);
	DrawLine3D(Vector3Zero(), Vector3{ 0, 0, -100}, BLUE);
	for (std::shared_ptr<Entity>& entity : m_sceneEntities)
	{
		entity->Draw();
	}
	EndMode3D();
}

void Scene::Add(const std::shared_ptr<Entity>& entity)
{
	m_sceneEntities.emplace_back(entity);
}



void Scene::SetMainCamera(const std::shared_ptr<Camera>& camera)
{
	m_mainCamera = camera;
}

const std::vector<std::shared_ptr<Entity>>& Scene::GetEntities() const
{
	return m_sceneEntities;
}
