#pragma once
#include <Components/TransformComponent.h>

#include "Entity.h"

class MyEntity : public Entity
{
private:
	TransformComponent m_transform;

	Mesh m_cubeMesh;
	Material m_cubeMaterial;
	
public:
	void Initialize() override;
	void Draw() override;
};

