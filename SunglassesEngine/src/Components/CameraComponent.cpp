#include "CameraComponent.h"

CameraComponent::CameraComponent()
{
	m_camera = std::make_shared<Camera>();
	SetPosition(Vector3Zero());
	SetType(CameraProjection::CAMERA_PERSPECTIVE);
	SetFov(m_camera->fovy = 60);
}

void CameraComponent::SetFov(float fov) const
{
	m_camera->fovy = fov;
}

void CameraComponent::SetType(CameraProjection projectionType) const
{
	m_camera->projection = projectionType;
}

Vector3 CameraComponent::Target() const
{
	return Vector3Add(Position(), Forward());
}

void CameraComponent::UpdateCamera() const
{
	m_camera->position = Position();
	m_camera->target = Target();
	m_camera->up = Up();
}

std::shared_ptr<Camera3D> CameraComponent::GetCamera()
{
	return m_camera;
}
