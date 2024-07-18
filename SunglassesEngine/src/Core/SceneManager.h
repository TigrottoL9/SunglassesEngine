#pragma once
#include <memory>
#include "../Scene.h"

class SceneManager
{

public:
	SceneManager(const SceneManager&) = delete;

	static SceneManager& Get()
	{
		static SceneManager instance;
		return instance;
	}

	static void GoToScene(const ScenePtr& newScene);
	static ScenePtr& CurrentScene();

private:
	SceneManager() = default;

	void SetCurrentScene(const ScenePtr& newScene);

private:
	ScenePtr m_currentScene;
};