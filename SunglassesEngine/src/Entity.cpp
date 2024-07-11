#include "Entity.h"
#include "raymath.h"

Entity::Entity()
{
	m_transform.translation = Vector3Zero();
	m_transform.rotation = QuaternionIdentity();
	m_transform.scale = Vector3One();

	m_material = LoadMaterialDefault();
	m_mesh = GenMeshCube(1, 1, 1);

	m_isTransformChanged = false;
}

void Entity::SetPosition(Vector3 position)
{
	m_transform.translation = position;
	m_isTransformChanged = true;
}

void Entity::SetRotation(Quaternion rotation)
{
	m_transform.rotation = rotation;
	m_isTransformChanged = true;
}

void Entity::SetScale(Vector3 scale)
{
	m_transform.scale = scale;
	m_isTransformChanged = true;
}

void Entity::AddPosition(Vector3 position)
{
	m_transform.translation = Vector3Add(m_transform.translation, position);
	m_isTransformChanged = true;
}

void Entity::AddRotation(Quaternion rotation)
{
	m_transform.rotation = QuaternionAdd(m_transform.rotation, rotation);
	m_isTransformChanged = true;
}

void Entity::AddScale(Vector3 scale)
{
	m_transform.scale = Vector3Add(m_transform.scale, scale);
	m_isTransformChanged = true;
}

/*
Transform& Entity::GetTransform()
{
	return m_transform;
}

Material& Entity::GetMaterial()
{
	return m_material;
}

Mesh& Entity::GetMesh()
{
	return m_mesh;
}
*/

bool Entity::IsTransformChanged() const
{
	return m_isTransformChanged;
}
