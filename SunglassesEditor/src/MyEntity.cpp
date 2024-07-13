#include "MyEntity.h"
#include <memory>

void MyEntity::Initialize()
{
	Add(std::make_shared<Mybehaviour>(m_transform));

	m_cubeMesh = GenMeshCube(5, 5, 8);

	m_cubeMaterial = LoadMaterialDefault();
	m_cubeMaterial.maps[MATERIAL_MAP_DIFFUSE].color = RED;
}


void MyEntity::Draw()
{
	DrawMesh(m_cubeMesh, m_cubeMaterial, m_transform.GetModelMatrix());
}
