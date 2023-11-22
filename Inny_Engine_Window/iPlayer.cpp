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

		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}
	
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}