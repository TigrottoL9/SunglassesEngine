#pragma once
#include "Behaviours/Behaviour.h"
#include "Components/CameraComponent.h"
#include "Components/TransformComponent.h"

class FPSCamera : public Behaviour
{
public:
	FPSCamera(TransformComponent& m_transform, CameraComponent& camera);
	void Update() override;

	void SetCameraHeigth(float heigth);
	void SetLookSensitivity(float sensitivity);
	void CheckCursor() const;

private:
	TransformComponent& m_transform;
	CameraComponent& m_camera;

	float m_cameraHeigth;
	float m_lookSensitivity;

	bool m_isFocuesed;
};
