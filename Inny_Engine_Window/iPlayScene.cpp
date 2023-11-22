#include "iPlayScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "iInput.h"
#include "iTitleScene.h"
#include "iSceneManager.h"

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
			bg = new Player();

			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"Play_TR");

			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->SetName(L"Play_SR");
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Standard Farm.png");

			AddGameObject(bg, eLayerType::Background);
		}

		{
			Animal = new Player();

			Transform* tr = Animal->AddComponent<Transform>();
			tr->SetPos(Vector2(600, 100));
			tr->SetName(L"Animal_TR");

			SpriteRender* sr = Animal->AddComponent<SpriteRender>();
			sr->SetName(L"Animal_SR");
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Chicken White.png");

			AddGameObject(Animal, eLayerType::NPC);
		}
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