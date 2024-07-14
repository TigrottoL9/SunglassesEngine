#include "MyEntity.h"

void MyEntity::Initialize()
{
	Add(std::make_shared<Mybehaviour>(m_transform));

	m_cubeMesh = GenMeshCube(5, 5, 8);

	//In teoria questa shader(e anche materiale?) potrebbe essere usata più volte da un sacco di oggetti
	//quindi non ha molto senso caricarla e compilarla ogni volta che viene creato un oggetto
	//Per il momento pace
	m_cubeMaterial = LoadMaterialDefault();
	m_cubeMaterial.shader = LoadShader("resources/shaders/basic.vs", "resources/shaders/basic.fs");
	m_cubeMaterial.maps[MATERIAL_MAP_DIFFUSE].color = RED;
}


void MyEntity::Draw()
{
	DrawMesh(m_cubeMesh, m_cubeMaterial, m_transform.GetModelMatrix());
}
