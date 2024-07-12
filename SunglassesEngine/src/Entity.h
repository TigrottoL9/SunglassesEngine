#pragma once
#include "raylib.h"

class Entity
{
public:

public:
	Entity();
	~Entity() = default;

	void Initialize() {};
	void Update() {};

private:
	Material m_material;
	Mesh m_mesh;
};

