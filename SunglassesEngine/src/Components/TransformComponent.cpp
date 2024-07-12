#include "TransformComponent.h"

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
	m_transform.rotation = QuaternionAdd(m_transform.rotation, rotationAmount);
	m_isDirty = true;
}

void TransformComponent::Scale(Vector3 scalingAmount)
{
	m_transform.scale = Vector3Add(m_transform.scale, scalingAmount);
	m_isDirty = true;
}

Matrix TransformComponent::GetModelMatrix()
{
	if (!m_isDirty)
		return m_modelMatrix;

	//Questo processo può essere semplificato, ma per chiarezza ho messo le tre matrici staccate
	//Nulla vieta di fare la moltiplicazione senza queste variabili
	Matrix translation = MatrixTranslate(Position().x, Position().y, Position().z);
	Matrix scale = MatrixScale(Scale().x, Scale().y, Scale().z);
	Matrix rotation = QuaternionToMatrix(Rotation());
	m_modelMatrix = MatrixMultiply(translation, MatrixMultiply(rotation, scale));

	return m_modelMatrix;
}

const Vector3& TransformComponent::Position()
{
	return m_transform.translation;
}

const Quaternion& TransformComponent::Rotation()
{
	return m_transform.rotation;
}

const Vector3& TransformComponent::Scale()
{
	return m_transform.scale;
}