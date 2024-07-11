#pragma once
#include "raylib.h"

class Entity
{
	// model rayib 
public:

public:
	Entity();
	~Entity() = default;

	void Initialize() {};
	void Update() {};

public:
	void SetPosition(Vector3 position);
	void SetRotation(Quaternion rotation);
	void SetScale(Vector3 scale);

	void AddPosition(Vector3 position);
	void AddRotation(Quaternion rotation);
	void AddScale(Vector3 scale);

public:
	//Transform& GetTransform();
	//Material& GetMaterial();
	//Mesh& GetMesh();
	bool IsTransformChanged() const;

private:
	bool m_isTransformChanged;
	Transform m_transform;
	Material m_material;
	Mesh m_mesh;
};

