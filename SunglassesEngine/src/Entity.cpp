#include "Entity.h"
#include "raymath.h"

Entity::Entity()
{
	m_material = LoadMaterialDefault();
	m_mesh = GenMeshCube(1, 1, 1);
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