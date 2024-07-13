#include "Entity.h"
#include "raymath.h"

Entity::Entity()
{
	m_material = LoadMaterialDefault();
	m_mesh = GenMeshCube(1, 1, 1);
}
