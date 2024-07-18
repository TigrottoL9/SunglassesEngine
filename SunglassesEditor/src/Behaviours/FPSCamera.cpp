#include "FPSCamera.h"

#include <iostream>

FPSCamera::FPSCamera(TransformComponent& transform, CameraComponent& camera)
	: m_transform(transform), m_camera(camera), m_cameraHeigth(1), m_lookSensitivity(0.001f), m_isFocuesed(true)
{
	CheckCursor();
	m_camera.SetPosition(Vector3Add(m_transform.Position(), Vector3{ 0, m_cameraHeigth, 0 }));
}

void FPSCamera::Update()
{
	if (IsKeyPressed(KEY_ESCAPE))
	{
		m_isFocuesed = !m_isFocuesed;
		CheckCursor();
	}

	if(m_isFocuesed)
	{
		Vector2 mouseDelta = Vector2Scale(GetMouseDelta(), m_lookSensitivity);

		Quaternion horiz = QuaternionFromAxisAngle(Vector3{ 0, 1, 0 }, -mouseDelta.x);
		Quaternion vert = QuaternionFromAxisAngle(Vector3{ 1, 0, 0 }, -mouseDelta.y);

		m_camera.SetRotation(QuaternionMultiply(horiz, QuaternionMultiply(m_camera.Rotation(), vert)));
		m_transform.Rotate(horiz);
		m_camera.SetPosition(Vector3Add(m_transform.Position(), Vector3{ 0, m_cameraHeigth, 0 }));
		m_camera.UpdateCamera();
	}
}

void FPSCamera::SetCameraHeigth(float heigth)
{
	m_cameraHeigth = heigth;
}

void FPSCamera::SetLookSensitivity(float sensitivity)
{
	m_lookSensitivity = sensitivity;
}

void FPSCamera::CheckCursor() const
{
	if (m_isFocuesed)
	{
		DisableCursor();
	}
	else
	{
		EnableCursor();
	}
	
}
