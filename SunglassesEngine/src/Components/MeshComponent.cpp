#include "MeshComponent.h"

MeshComponent::MeshComponent() : m_meshes()
{
}

void MeshComponent::Add(Mesh& mesh)
{
	m_meshes.emplace_back(mesh);
}

void MeshComponent::Load(const std::string& modelFileName)
{
	if (!m_meshes.empty())
	{
		m_meshes.clear();
	}

	Model model = LoadModel(modelFileName.c_str());
	for (int i = 0; i < model.meshCount; i++)
	{
		m_meshes.emplace_back(model.meshes[i]);
	}
}

Mesh& MeshComponent::GetMesh(int index)
{
	return m_meshes[index];
}

int MeshComponent::MeshCount() const
{
	return m_meshes.size();
}
