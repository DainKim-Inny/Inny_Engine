#include "iBeachScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "iInput.h"
#include "iSceneManager.h"
#include "iObject.h"

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
			bg = Object::Instantiate<Player>(eLayerType::Background, Vector2(0.0f, 0.0f));
			SpriteRender* sr = bg->AddComponent < SpriteRender>();
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Beach Overview.png");
		}

		Scene::Initialize();
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