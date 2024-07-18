#pragma once
#include "../Core/Entity.h"
#include "../Components/TransformComponent.h"
#include "../Components/MeshComponent.h"

class RenderableEntity: public Entity
{
protected:
	TransformComponent m_transform;
	MeshComponent m_mesh;
	Material m_material;

public:
	RenderableEntity();

	virtual void Initialize() override;
	virtual void Draw() override;
};