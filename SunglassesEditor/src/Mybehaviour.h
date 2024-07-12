#pragma once

#include "Behaviours/Behaviour.h"
#include "Components/TransformComponent.h"

class Mybehaviour : Behaviour
{
public:
	Mybehaviour(TransformComponent& component);
	//Mybehaviour(std::vector<IComponent>& components) {};



	// Inherited via Behaviour
	void Update() override;

private:
	TransformComponent& m_transformComponent;
};

