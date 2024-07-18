#include "RenderableEntity.h"

RenderableEntity::RenderableEntity()
{
	m_material = LoadMaterialDefault();
	m_material.shader = LoadShader("resources/shaders/basic.vs", "resources/shaders/basic.fs");
	m_material.maps[MATERIAL_MAP_DIFFUSE].color = WHITE;
}

void RenderableEntity::Initialize()
{
}

void RenderableEntity::Draw()
{
	for (int i = 0; i < m_mesh.MeshCount(); i++)
	{
		DrawMesh(m_mesh.GetMesh(i), m_material,m_transform.GetModelMatrix());
	}
}
