#include "CameraOrbit.h"
#include "../Core/SceneManager.h"

#include "raymath.h"
#include <iostream>

void CameraOrbit::Initialize()
{
	SceneManager::CurrentScene()->SetMainCamera(m_camera.GetCamera());
	m_camera.SetPosition(Vector3{ 15.0f, 10.0f, 0 });
	m_camera.SetTarget(Vector3{ 0.0f, .0f, 0.0f });

	alpha = 0;
	beta = 0;
}

void CameraOrbit::Update()
{
	float scrollDelta = GetMouseWheelMove();
	if (IsMouseButtonDown(0))
	{
		Vector2 mouseDelta = GetMouseDelta();

		alpha = -mouseDelta.x * GetFrameTime() * 40;
		beta = -mouseDelta.y * GetFrameTime() * 40;

		Quaternion rotUp = QuaternionFromAxisAngle(Vector3{0, 1, 0}, alpha * DEG2RAD);
		Quaternion rotRigth = QuaternionFromAxisAngle(m_camera.Rigth(), beta * DEG2RAD);
		Quaternion rot = QuaternionMultiply(rotUp, rotRigth);

		m_camera.SetPosition(Vector3RotateByQuaternion(m_camera.Position(), rot));
	}
	else if (scrollDelta != 0)
	{
		m_camera.SetPosition(Vector3Add(m_camera.Position(), Vector3Scale(m_camera.Forward(), scrollDelta)));
	}
}
