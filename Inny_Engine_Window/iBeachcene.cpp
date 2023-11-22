#include "iBeachScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "iInput.h"
#include "iSceneManager.h"

using namespace std;

namespace in
{
	BeachScene::BeachScene()
		: bg(nullptr)
	{

	}

	BeachScene::~BeachScene()
	{

	}
	
	void BeachScene::Initialize()
	{
		{
			bg = new Player();

			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"Beach_TR");

			SpriteRender* sr = bg->AddComponent < SpriteRender>();
			sr->SetName(L"Beach_SR");
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Beach Overview.png");

			AddGameObject(bg, eLayerType::Background);
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

		wchar_t str[50] = L"Beach Scene";
		TextOut(hdc, 0, 0, str, 11);
	}

	void BeachScene::OnEnter()
	{
		Scene::OnEnter();
	}
	
	void BeachScene::OnExit()
	{
		Scene::OnExit();
	}
}