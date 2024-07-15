#pragma once
#include <string>

#include "Scene.h"

//Application secondo me dovrebbe tenere dati dell'appicazione (assurdo), tipo nome, flag per vsync o window resize
//Inoltre si dovrebbe occupare di far girare Game (il gioco in se) che contiene scene, sceglie da che scena partire ecc...
//Questa seconda cosa non l'ho ancora implementata e infatti al momeno scene si tiene una scena e la fa girare
class App
{
public:
	App(std::string applicationName, int windowWidth, int windowHeigth);

	void Initialize();
	void Run();
	void Shutdown();

	void SetScene(Scene* scene);

private:
	Scene* m_currentScene;
	
	bool m_isGameRunning;
};

