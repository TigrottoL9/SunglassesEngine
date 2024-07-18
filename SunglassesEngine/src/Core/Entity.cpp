#include "Entity.h"
#include "raymath.h"

Entity::Entity()
{
}

void Entity::Update()
{
	for (std::shared_ptr<Behaviour> behaviour: m_behaviours)
	{
		behaviour->Update();
	}
}

void Entity::Add(const std::shared_ptr<Behaviour>& behaviour)
{
	m_behaviours.push_back(behaviour);
}
