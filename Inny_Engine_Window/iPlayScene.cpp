#include "iPlayScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "iInput.h"
#include "iTitleScene.h"
#include "iSceneManager.h"
#include "iObject.h"

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
		{
			bg = Object::Instantiate<Player>(eLayerType::Background, Vector2(0.0f, 0.0f));
			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Standard Farm.png");
		}

		{
			Animal = Object::Instantiate<Player>(eLayerType::NPC, Vector2(600.0f, 100.0f));
			SpriteRender* sr = Animal->AddComponent<SpriteRender>();
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Chicken White.png");
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
			SceneManager::LoadScene(L"TitleScene");
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