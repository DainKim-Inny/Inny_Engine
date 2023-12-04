#include "iChickenScript.h"
#include "iInput.h"
#include "iTransform.h"
#include "ITime.h"
#include "iGameObject.h"
#include "iAnimator.h"

namespace in
{
    ChickenScript::ChickenScript()
        : mState(eChickenState::SitDown)
        , mAnimator(nullptr)
    {
    }

    ChickenScript::~ChickenScript()
    {
    }
    
    void ChickenScript::Initialize()
    {
    }
    
    void ChickenScript::Update()
    {
        if (mAnimator == nullptr)
        {
            mAnimator = GetOwner()->GetComponent<Animator>();
        }

        switch (mState)
        {
        case in::ChickenScript::eChickenState::SitDown:
            sitDown();
            break;
        case in::ChickenScript::eChickenState::Walk:
            move();
            break;

        case in::ChickenScript::eChickenState::Sleep:
            break;
        case in::ChickenScript::eChickenState::Relex:
            break;
        case in::ChickenScript::eChickenState::Eat:
            break;
        default:
            break;
        }
    }
    
    void ChickenScript::LateUpdate()
    {
    }
    
    void ChickenScript::Render(HDC hdc)
    {
    }
    
    void ChickenScript::sitDown()
    {
        if (Input::GetKey(eKeyCode::D))
        {
            mState = ChickenScript::eChickenState::Walk;
            mAnimator->PlayAnimation(L"RightWalk");
        }

        if (Input::GetKey(eKeyCode::A))
        {
            mState = ChickenScript::eChickenState::Walk;
            mAnimator->PlayAnimation(L"LeftWalk");
        }
        if (Input::GetKey(eKeyCode::W))
        {
            mState = ChickenScript::eChickenState::Walk;
            mAnimator->PlayAnimation(L"UpWalk");
        }
        if (Input::GetKey(eKeyCode::S))
        {
            mState = ChickenScript::eChickenState::Walk;
            mAnimator->PlayAnimation(L"DownWalk");
        }
    }
    
    void ChickenScript::move()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();

        if (Input::GetKey(eKeyCode::D))
        {
            pos.x += 100.0f * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::A))
        {
            pos.x -= 100.0f * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::W))
        {
            pos.y -= 100.0f * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::S))
        {
            pos.y += 100.0f * Time::DeltaTime();
        }

        tr->SetPosition(pos);

        if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A)
            || Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
        {
            mState = ChickenScript::eChickenState::SitDown;
            mAnimator->PlayAnimation(L"Relex", true);
        }
    }
}