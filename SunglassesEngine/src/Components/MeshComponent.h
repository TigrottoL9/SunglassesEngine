#pragma once
#include <raylib.h>

#include "IComponent.h"
#include <string>
#include <vector>

class MeshComponent : public IComponent
{
public:
	MeshComponent();

	void Add(Mesh& mesh);
	void Load(const std::string& modelFileName);

	Mesh& GetMesh(int index);
	int MeshCount() const;

private:
	std::vector<Mesh> m_meshes;
};