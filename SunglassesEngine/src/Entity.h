#pragma once
#include <raylib.h>
#include <vector>
#include <memory>

#include "Components/TransformComponent.h"
#include "Behaviours/Behaviour.h"

class Entity
{
public:

public:
	Entity();
	~Entity() = default;

	virtual void Initialize() {};
	virtual void Update();

	virtual void Draw() {};

	void Add(std::shared_ptr<Behaviour> behaviour);

private:
	std::vector<std::shared_ptr<Behaviour>> m_behaviours;

};

