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
        , mTime(0.0f)
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
            sleep();
            break;
        case in::ChickenScript::eChickenState::Relex:
            relex();
            break;
        case in::ChickenScript::eChickenState::Eat:
            eat();
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
        mTime += Time::DeltaTime();

        if (mTime > 3.0f)
        {
            mState = ChickenScript::eChickenState::Walk;
            int direction = (rand() % 4);
            mDirection = (eDirection)direction;
            PlaywalkAnimationByDirection(mDirection);
            mTime = 0.0f;
        }
    }
    
    void ChickenScript::move()
    {
        mTime += Time::DeltaTime();
        if (mTime > 2.0f)
        {
            int eatting = rand() % 2;

            if (eatting)
            {
                mState = eChickenState::SitDown;
                mAnimator->PlayAnimation(L"Chicken_SitDown", true);
            }
            else
            {
                mState = eChickenState::SitDown;
                mAnimator->PlayAnimation(L"Chicken_SitDown", true);
            }
        }

        Transform* tr = GetOwner()->GetComponent<Transform>();
        translate(tr);
    }

    void ChickenScript::sleep()
    {

    }
    
    void ChickenScript::relex()
    {
        mState = eChickenState::Relex;
        mAnimator->PlayAnimation(L"Chicken_Rexle", true);
    }
    
    void ChickenScript::eat()
    {
        mState = eChickenState::Eat;
        mAnimator->PlayAnimation(L"Chicken_Eatting", true);
    }
    
    void ChickenScript::PlaywalkAnimationByDirection(eDirection dir)
    {
        switch (dir)
        {
        case ChickenScript::eDirection::Left:
            mAnimator->PlayAnimation(L"Chicken_LeftWalk", true);
            break;
        case ChickenScript::eDirection::Right:
            mAnimator->PlayAnimation(L"Chicken_RightWalk", true);
            break;
        case ChickenScript::eDirection::Up:
            mAnimator->PlayAnimation(L"Chicken_UpWalk", true);
            break;
        case ChickenScript::eDirection::Down:
            mAnimator->PlayAnimation(L"Chicken_DownWalk", true);
            break;
        default:
            assert(false);
            break;
        }
    }
    
    void ChickenScript::translate(Transform* tr)
    {
        Vector2 pos = tr->GetPosition();

        switch (mDirection)
        {
        case ChickenScript::eDirection::Left:
            pos.x -= 100.0f * Time::DeltaTime();
            break;
        case ChickenScript::eDirection::Right:
            pos.x += 100.0f * Time::DeltaTime();
            break;
        case ChickenScript::eDirection::Up:
            pos.y -= 100.0f * Time::DeltaTime();
            break;
        case ChickenScript::eDirection::Down:
            pos.y += 100.0f * Time::DeltaTime();
            break;
        default:
            assert(false);
            break;
        }

        tr->SetPosition(pos);
    }
}