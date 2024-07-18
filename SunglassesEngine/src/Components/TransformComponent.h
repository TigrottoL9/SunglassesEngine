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
		void LookAt(Vector3 point);

		Vector3 TransformVector(const Vector3& v) const;

		//void LookAt(Vector3 point);

		Matrix GetModelMatrix();

		const Vector3& Position() const;
		const Quaternion& Rotation() const;
		const Vector3& Scale() const;

		const Vector3& Up() const;
		const Vector3& Forward() const;
		const Vector3& Rigth() const;

	private:
		Transform m_transform;
		Matrix m_modelMatrix;
		bool m_isDirty;
};

