#pragma once
#include <Core/Entity.h>
#include <Components/TransformComponent.h>
#include <Components/CameraComponent.h>

class CameraOrbit : public Entity
{
private:
	TransformComponent m_transform;
	CameraComponent m_camera;

public:
	void Initialize() override;
	void Update() override;
};
