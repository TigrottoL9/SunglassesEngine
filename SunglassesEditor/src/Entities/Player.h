#pragma once
#include <Core/Entity.h>

#include <Components/CameraComponent.h>
#include "Components/TransformComponent.h"

class Player : public Entity
{
private:
	TransformComponent m_transform;
	CameraComponent m_camera;

public:
	void Initialize() override;
	void Update() override;
	
};
