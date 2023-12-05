#include "iPlayScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iCamera.h"
#include "iObject.h"
#include "iInput.h"
#include "iRenderer.h"
#include "iSpriteRender.h"
#include "iResources.h"
#include "iPlayerScript.h"
#include "iAnimator.h"
#include "iChickenScript.h"

using namespace std;

namespace in
{
	PlayScene::PlayScene()
		: bg(nullptr), mChicken(nullptr), mPlayer(nullptr)
	{
	}

	PlayScene::~PlayScene()
	{
	}
	
	void PlayScene::Initialize()
	{
		GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, Vector2(820.0f, 470.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		{
			bg = Object::Instantiate<Player>(eLayerType::None);

			Object::Instantiate<Player>(eLayerType::Player);


			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->SetSize(Vector2(1.7f, 1.2f));

			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"Play BG");
			sr->SetTexture(bg);
		}

		{
			mPlayer = Object::Instantiate<Player>(eLayerType::Player);
			mPlayer->AddComponent<PlayerScript>();

			graphics::Texture* PlayerTexture = Resources::Find<graphics::Texture>(L"Player");

			Animator* playerAnimator = mPlayer->AddComponent<Animator>();

			playerAnimator->CreateAnimation(L"FrontStay", PlayerTexture
				, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);

			// RightWalk
			playerAnimator->CreateAnimation(L"RightWalk", PlayerTexture
				, Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);

			playerAnimator->CreateAnimation(L"RightWalkStop", PlayerTexture
				, Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);

			// LeftWalk
			playerAnimator->CreateAnimation(L"LeftWalk", PlayerTexture
				, Vector2(1500.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);

			playerAnimator->CreateAnimation(L"LeftWalkStop", PlayerTexture
				, Vector2(1500.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);

			// DownWalk
			playerAnimator->CreateAnimation(L"DownWalk", PlayerTexture
				, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 4, 0.1f);

			playerAnimator->CreateAnimation(L"DownWalkStop", PlayerTexture
				, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);

			// UpWalk
			playerAnimator->CreateAnimation(L"UpWalk", PlayerTexture
				, Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 8, 0.1f);
			
			playerAnimator->CreateAnimation(L"UpWalkStop", PlayerTexture
				, Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);

			playerAnimator->PlayAnimation(L"FrontStay", false);

			mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));

		}

		{
			mChicken = Object::Instantiate<Player>(eLayerType::NPC);
			mChicken->AddComponent<ChickenScript>();

			graphics::Texture* AnimalTexture = Resources::Find<graphics::Texture>(L"Chicken2");
			
			Animator* animator = mChicken->AddComponent<Animator>();

			animator->CreateAnimation(L"Chicken_LeftWalk", AnimalTexture
				, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);

			animator->CreateAnimation(L"Chicken_RightWalk", AnimalTexture
				, Vector2(0.0f, 16.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);

			animator->CreateAnimation(L"Chicken_UpWalk", AnimalTexture
				, Vector2(0.0f, 32.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);

			animator->CreateAnimation(L"Chicken_DownWalk", AnimalTexture
				, Vector2(0.0f, 48.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);

			animator->CreateAnimation(L"Chicken_Relex", AnimalTexture
				, Vector2(0.0f, 64.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);

			animator->CreateAnimation(L"Chicken_SitDown", AnimalTexture
				, Vector2(0.0f, 80.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);

			animator->CreateAnimation(L"Chicken_Eatting", AnimalTexture
				, Vector2(0.0f, 96.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);

			animator->PlayAnimation(L"Chicken_SitDown", true);

			mChicken->GetComponent<Transform>()->SetPosition(Vector2(600.0f, 600.0f));
			mChicken->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		}

		Scene::Initialize();
	}
	
	void PlayScene::Update()
	{
		Scene::Update();
	}
	
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"BeachScene");
		}
	}
	
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}
	
	void PlayScene::OnExit()
	{
		Scene::OnExit();
	}
}