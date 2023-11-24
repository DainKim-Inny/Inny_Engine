#include "iPlayer.h"
#include "iInput.h"
#include "iTransform.h"
#include "ITime.h"

namespace in
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}
	
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}