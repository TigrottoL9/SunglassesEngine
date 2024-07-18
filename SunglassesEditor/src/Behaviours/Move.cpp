#include "Move.h"

Move::Move(TransformComponent& transform) : m_transform(transform), m_velocity(Vector3Zero())
{
}

void Move::Update()
{
	float fMovement;
	if (IsKeyDown(KEY_S))
		fMovement = IsKeyDown(KEY_W) ? 1 : -1;
	else
		fMovement = IsKeyDown(KEY_W) ? 1 : 0;

	float rMovement;
	if (IsKeyDown(KEY_A))
		rMovement = IsKeyDown(KEY_D) ? 1 : -1;
	else
		rMovement = IsKeyDown(KEY_D) ? 1 : 0;

	Vector3 direction = Vector3{ rMovement , 0, fMovement };
	direction = Vector3Normalize(direction);
	direction = m_transform.TransformVector(direction);

										//AccelerationVector
	m_velocity = Vector3Add(m_velocity, Vector3Scale(direction, 100 * GetFrameTime()));
																	//Deceleration or Damping
	m_velocity = Vector3Lerp(m_velocity, Vector3Zero(), 5 * GetFrameTime());

	m_transform.Translate(Vector3Scale(m_velocity,  GetFrameTime()));
}
