#include "iBirdScript.h"
#include "iInput.h"
#include "iTransform.h"
#include "iTime.h"
#include "iGameObject.h"

namespace in
{
	BirdScript::BirdScript()
	{
	}

	BirdScript::~BirdScript()
	{
	}
	
	void BirdScript::Initialize()
	{
	}
	
	void BirdScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x -= 100.0f * Time::DeltaTime();

		if (pos.x < 0.0)
		{
			pos.x = 1550.0f;
		}
		tr->SetPosition(pos);
	}
	
	void BirdScript::LateUpdate()
	{
	}
	
	void BirdScript::Render(HDC hdc)
	{
	}
}
