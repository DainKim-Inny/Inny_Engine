#include "iPlayerScript.h"
#include "iInput.h"
#include "iTransform.h"
#include "iTime.h"
#include "iGameObject.h"
#include "iAnimator.h"

namespace in
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}
	
	void PlayerScript::Initialize()
	{
	}
	
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case in::PlayerScript::eState::Idle:
			idle();
			break;
		case in::PlayerScript::eState::Walk:
			move();
			break;
		case in::PlayerScript::eState::UsingAxes:
			usingAxes();
			break;
		case in::PlayerScript::eState::UsingHoes:
			//usingHoes();
			break;
		case in::PlayerScript::eState::UsingScythe:
			//usingScythe();
			break;
		case in::PlayerScript::eState::UsingPickaxes:
			//usingPickaxes();
			break;
		default:
			break;
		}
	}
	
	void PlayerScript::LateUpdate()
	{
	}
	
	void PlayerScript::Render(HDC hdc)
	{
	}

	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk");
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk");
		}
		if (Input::GetKey(eKeyCode::LButton))
		{
			mState = PlayerScript::eState::UsingAxes;
			mAnimator->PlayAnimation(L"UsingAxes", false);

			Vector2 mousePos = Input::GetMousePosition();
		}

	}
	
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"RightWalkStop", true);
		}

		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"LeftWalkStop", true);
		}

		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"DownWalkStop", true);
		}

		if (Input::GetKeyUp(eKeyCode::Up))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"UpWalkStop", true);
		}

	}
	void PlayerScript::usingAxes()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
	//void PlayerScript::usingHoes()
	//{
	//}
	//void PlayerScript::usingScythe()
	//{
	//}
	//void PlayerScript::usingPickaxes()
	//{
	//}
}
