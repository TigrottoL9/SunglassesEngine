#include "CameraComponent.h"

CameraComponent::CameraComponent()
{
	m_camera = std::make_shared<Camera>();
	SetPosition(Vector3Zero());
	SetTarget(Vector3Zero());
	SetType(CameraProjection::CAMERA_PERSPECTIVE);
	SetFov(m_camera->fovy = 60);
}

void CameraComponent::SetPosition(Vector3 position)
{
	m_camera->position = position;

	m_right = Vector3Normalize(Vector3CrossProduct(Forward(), Vector3{ 0, 1, 0 }));
	m_camera->up = Vector3Normalize(Vector3CrossProduct(m_right, Forward()));
}

void CameraComponent::SetTarget(Vector3 target)
{
	m_camera->target = target;

	m_right = Vector3Normalize(Vector3CrossProduct(Forward(), Vector3{ 0, 1, 0 }));
	m_camera->up = Vector3Normalize(Vector3CrossProduct(m_right, Forward()));
}

void CameraComponent::SetFov(float fov)
{
	m_camera->fovy = fov;
}

void CameraComponent::SetType(CameraProjection projectionType)
{
	m_camera->projection = projectionType;
}

Vector3& CameraComponent::Position() const
{
	return m_camera->position;
}

Vector3& CameraComponent::Target() const
{
	return m_camera->target;
}

Vector3 CameraComponent::Forward() const
{
	return Vector3Normalize(Vector3Subtract(m_camera->target, Position()));
}

Vector3& CameraComponent::Up() const
{
	return m_camera->up;
}

Vector3 CameraComponent::Rigth() const
{
	return m_right;
}

std::shared_ptr<Camera3D> CameraComponent::GetCamera()
{
	return m_camera;
}