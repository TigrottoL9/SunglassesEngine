#include "CameraOrbit.h"

#include <ios>

#include "raymath.h"
#include <Core/SceneManager.h>

void CameraOrbit::Initialize()
{
	SceneManager::CurrentScene()->SetMainCamera(m_camera.GetCamera());
	//m_camera.SetPosition(Vector3{ 0, 10.0f, 10.0f});
	//m_camera.SetTarget(Vector3{ 0.0f, 0.0f, 0.0f });
}

void CameraOrbit::Update()
{
	/*
	if(IsKeyPressed(KEY_PERIOD))
	{
		//m_camera.SetPosition(Vector3{ 15.0f, 10.0f, 0 });
		//m_camera.SetTarget(Vector3{ 0.0f, .0f, 0.0f });
	}

	float scrollDelta = GetMouseWheelMove();
	if (IsMouseButtonDown(0))
	{
		Vector2 mouseDelta = GetMouseDelta();

		float alpha = -mouseDelta.x * GetFrameTime() * 40;
		float beta = -mouseDelta.y * GetFrameTime() * 40;

		Quaternion rotUp = QuaternionFromAxisAngle(m_camera.Up(), alpha * DEG2RAD);
		Quaternion rotRigth = QuaternionFromAxisAngle(m_camera.Rigth(), beta * DEG2RAD);
		Quaternion rot = QuaternionMultiply(rotUp, rotRigth);

		Vector3 newPosition = Vector3RotateByQuaternion(m_camera.Position(), rot);

		Vector3 originToCamera = Vector3Normalize(Vector3Subtract(newPosition, Vector3{ 0, 0, 0 }));
		float closenessToAxis = Vector3DotProduct(originToCamera, Vector3{ 0, 1, 0 });
		if (closenessToAxis >= 0.99 || closenessToAxis <= -0.99)
		{
			return;
		}
		m_camera.SetPosition(newPosition);
	}
	else if (IsMouseButtonDown(1))
	{
		Vector2 mouseDelta = GetMouseDelta();
		Vector3 flattenedForward = m_camera.Forward();
		flattenedForward.y = 0;
		flattenedForward = Vector3Normalize(flattenedForward);

		Vector3 xMovement = Vector3Scale(m_camera.Rigth(), mouseDelta.x * 10 * GetFrameTime());
		Vector3 zMovement = Vector3Scale(flattenedForward, -mouseDelta.y * 10 * GetFrameTime());
		Vector3 movement = Vector3Add(xMovement, zMovement);

		m_camera.SetTarget(Vector3Add(m_camera.Target(), movement));
		m_camera.SetPosition(Vector3Add(m_camera.Position(), movement));
	}
	else if (scrollDelta != 0)
	{
		m_camera.SetPosition(Vector3Add(m_camera.Position(), Vector3Scale(m_camera.Forward(), scrollDelta)));
	}
	*/
}
