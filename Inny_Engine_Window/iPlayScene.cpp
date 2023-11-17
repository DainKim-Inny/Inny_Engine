#include "iPlayScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"

using namespace std;

namespace in
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}
	
	void PlayScene::Initialize()
	{
		{
			Player* Play = new Player();

			Transform* tr = Play->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"Titel_TR");

			SpriteRender* sr = Play->AddComponent<SpriteRender>();
			sr->SetName(L"Title_SR");
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Standard Farm.png");

			AddGameObject(Play);
		}
	}
	
	void PlayScene::Update()
	{
		Scene::Update();
	}
	
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}