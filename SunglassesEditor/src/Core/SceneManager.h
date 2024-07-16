#pragma once
#include <memory>
#include "Scene.h"

class SceneManager
{

public:
	SceneManager(const SceneManager&) = delete;

	static SceneManager& Get()
	{
		static SceneManager instance;
		return instance;
	}

	static void GoToScene(ScenePtr newScene);
	static ScenePtr& CurrentScene();

private:
	SceneManager() {};

	void SetCurrentScene(ScenePtr newScene);

private:
	ScenePtr m_currentScene;
};