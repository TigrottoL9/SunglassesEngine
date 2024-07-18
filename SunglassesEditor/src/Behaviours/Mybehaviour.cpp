#include "Mybehaviour.h"

#include <raylib.h>
#include <iostream>


Mybehaviour::Mybehaviour(TransformComponent& component)
	: Behaviour(),
	m_transformComponent(component)
{
}

void Mybehaviour::Update()
{
	Vector3 translateAmount = Vector3{ 4.0f * GetFrameTime(), 0, 0 };
	m_transformComponent.Translate(translateAmount);
	//std::cout << GetFPS() << std::endl;
}
