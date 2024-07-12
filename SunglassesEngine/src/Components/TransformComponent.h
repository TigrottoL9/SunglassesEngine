#pragma once

#include "IComponent.h"

#include <raylib.h>
#include <raymath.h>

class TransformComponent : public IComponent
{
	public:
		TransformComponent();

		void SetPosition(Vector3 position);
		void SetRotation(Quaternion rotation);
		void SetScale(Vector3 scale);

		void Translate(Vector3 position);
		void Rotate(Quaternion rotation);
		void Scale(Vector3 scale);

		Matrix GetModelMatrix();

		const Vector3& Position();
		const Quaternion& Rotation();
		const Vector3& Scale();

	private:
		Transform m_transform;
		Matrix m_modelMatrix;
		bool m_isDirty;
};

