#include "Player.h"
#include <Core/SceneManager.h>

#include "../Behaviours/FPSCamera.h"
#include "../Behaviours/Move.h"

void Player::Initialize()
{
	Entity::Initialize();
	Add(std::make_shared<FPSCamera>(m_transform, m_camera));
	Add(std::make_shared<Move>(m_transform));

	SceneManager::CurrentScene()->SetMainCamera(m_camera.GetCamera());
}

void Player::Update()
{
	Entity::Update();
}
