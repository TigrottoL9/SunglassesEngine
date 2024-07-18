#pragma once
#include <Entities/RenderableEntity.h>

#include "../Behaviours/Mybehaviour.h"

class MyEntity : public RenderableEntity
{
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
};

