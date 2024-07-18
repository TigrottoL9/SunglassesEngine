#pragma once

#include "Behaviours/Behaviour.h"
#include "Components/TransformComponent.h"

class Mybehaviour : public Behaviour
{
public:
	Mybehaviour(TransformComponent& component);

	// Inherited via Behaviour
	void Update() override;

private:
	TransformComponent& m_transformComponent;
};

