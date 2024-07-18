#include "MyEntity.h"

#include "../../vendor/rlImGui/imgui.h"
#include "Core/SceneManager.h"

void MyEntity::Initialize()
{
	RenderableEntity::Initialize();

	m_mesh.Load("resources/models/testSeparati.glb");
	m_material.maps[MATERIAL_MAP_ALBEDO].color = RED;

	m_transform.Translate(Vector3{ 0, -1, 0 });
}

void MyEntity::Update()
{
}

void MyEntity::Draw()
{
	RenderableEntity::Draw();
}
