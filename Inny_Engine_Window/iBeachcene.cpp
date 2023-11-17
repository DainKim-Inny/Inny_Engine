#include "iBeachScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"

using namespace std;

namespace in
{
	BeachScene::BeachScene()
	{

	}

	BeachScene::~BeachScene()
	{

	}
	
	void BeachScene::Initialize()
	{
		{
			Player* Beach = new Player();

			Transform* tr = Beach->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"Beach_TR");

			SpriteRender* sr = Beach->AddComponent < SpriteRender>();
			sr->SetName(L"Beach_SR");
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Beach Overview.png");

			AddGameObject(Beach);
		}

	}
	
	void BeachScene::Update()
	{
		Scene::Update();
	}
	
	void BeachScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	
	void BeachScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}