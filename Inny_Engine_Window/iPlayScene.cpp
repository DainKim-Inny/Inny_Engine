#include "iPlayScene.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "iInput.h"
#include "iBeachScene.h"
#include "iSceneManager.h"
#include "iObject.h"
#include "iTexture.h"
#include "iResources.h"
#include "iPlayerScript.h"
#include "iCamera.h"
#include "iRenderer.h"
#include "iAnimator.h"

using namespace std;

namespace in
{
	PlayScene::PlayScene()
		: bg(nullptr), Animal(nullptr)
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
			bg = Object::Instantiate<Player>(eLayerType::Background);

			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->SetSize(Vector2(1.7f, 1.0f));

			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"Play BG");
			sr->SetTexture(bg);
		}

		{
			Animal = Object::Instantiate<Player>(eLayerType::NPC, Vector2(600.0f, 100.0f));
			Animal->AddComponent<PlayerScript>();

			graphics::Texture* AnimalTexture = Resources::Find<graphics::Texture>(L"Chicken2");
			Animator* animator = Animal->AddComponent<Animator>();
			animator->CreateAnimation(L"ChickenMove", AnimalTexture, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.5f);
			animator->PlayAnimation(L"ChickenMove", true);
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