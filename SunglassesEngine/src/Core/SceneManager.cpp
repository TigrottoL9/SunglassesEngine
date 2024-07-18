#include "SceneManager.h"

void SceneManager::GoToScene(const ScenePtr& newScene)
{
	Get().SetCurrentScene(newScene);
}

ScenePtr& SceneManager::CurrentScene()
{
	return Get().m_currentScene;
}

void SceneManager::SetCurrentScene(const ScenePtr& newScene)
{
	//TODO: Fai unload di m_currentScene

	m_currentScene = newScene;
	//TODO: Fai load di m_currentScene(?)
	m_currentScene->Initialize();
}
