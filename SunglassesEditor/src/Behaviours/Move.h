#pragma once
#include <Behaviours/Behaviour.h>

#include <Components/TransformComponent.h>

class Move : public Behaviour
{
public:
	Move(TransformComponent& transform);
	void Update() override;

private:
	TransformComponent& m_transform;

	Vector3 m_velocity;
};

