#include "TransformComponent.h"
#include <cmath>

TransformComponent::TransformComponent() : m_isDirty(true), m_transform(), m_modelMatrix(MatrixIdentity())
{
	m_transform.translation = Vector3Zero();
	m_transform.scale = Vector3One();
	m_transform.rotation = QuaternionIdentity();
}

void TransformComponent::SetPosition(Vector3 position)
{
	m_transform.translation = position;
	m_isDirty = true;
}

void TransformComponent::SetRotation(Quaternion rotation)
{
	m_transform.rotation = rotation;
	m_isDirty = true;
}

void TransformComponent::SetScale(Vector3 scale)
{
	m_transform.scale = scale;
	m_isDirty = true;
}

void TransformComponent::Translate(Vector3 translationAmount)
{
	m_transform.translation = Vector3Add(m_transform.translation, translationAmount);
	m_isDirty = true;
}

void TransformComponent::Rotate(Quaternion rotationAmount)
{
	m_transform.rotation = QuaternionMultiply(m_transform.rotation, rotationAmount);
	m_isDirty = true;
}

void TransformComponent::Scale(Vector3 scalingAmount)
{
	m_transform.scale = Vector3Add(m_transform.scale, scalingAmount);
	m_isDirty = true;
}


void TransformComponent::LookAt(Vector3 point)
{

	Vector3 dir = Vector3Normalize(Vector3Subtract(point, Position()));
	float dot = Vector3DotProduct(Vector3{ 0, 0, 1 }, dir);

	float rotAngle = std::acos(dot);
	Vector3 rotAxis = Vector3CrossProduct(Vector3{ 0, 0, 1 }, dir);
	rotAxis = Vector3Normalize(rotAxis);

	if(Vector3LengthSqr(rotAxis) == 0)
	{
		rotAxis = Up();
	}
	
	SetRotation(QuaternionFromAxisAngle(rotAxis, rotAngle));
}

Vector3 TransformComponent::TransformVector(const Vector3& v) const
{
	Vector3 result = Vector3Scale(Rigth(), v.x);
	result = Vector3Add(result, Vector3Scale(Forward(), v.z));
	result = Vector3Add(result, Vector3Scale(Up(), v.y));

	return result;
}


Matrix TransformComponent::GetModelMatrix()
{
	if (!m_isDirty)
		return m_modelMatrix;

	Vector3 translation = Position();
	Vector3 scale = Scale();
	Quaternion rotation = Rotation();

	//Questo processo puo essere semplificato, ma per chiarezza ho messo le tre matrici staccate
	//Nulla vieta di fare la moltiplicazione senza queste variabili
	Matrix translationMatrix = MatrixTranslate(translation.x, translation.y, translation.z);
	Matrix scaleMatrix = MatrixScale(scale.x, scale.y, scale.z);
	Matrix rotationMatrix = QuaternionToMatrix(rotation);
	m_modelMatrix = MatrixMultiply(translationMatrix, MatrixMultiply(rotationMatrix, scaleMatrix));

	return m_modelMatrix;
}

const Vector3& TransformComponent::Position() const
{
	return m_transform.translation;
}

const Quaternion& TransformComponent::Rotation() const
{
	return m_transform.rotation;
}

const Vector3& TransformComponent::Scale() const
{
	return m_transform.scale;
}

const Vector3& TransformComponent::Up() const
{
	return Vector3RotateByQuaternion(Vector3 {0, 1, 0}, m_transform.rotation);
}

const Vector3& TransformComponent::Forward() const
{
	return Vector3RotateByQuaternion(Vector3{ 0, 0, -1 }, m_transform.rotation);
}

const Vector3& TransformComponent::Rigth() const
{
	return Vector3RotateByQuaternion(Vector3{ 1, 0, 0 }, m_transform.rotation);
}
