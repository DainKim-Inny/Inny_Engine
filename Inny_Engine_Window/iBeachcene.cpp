#include "iBeachScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "iInput.h"
#include "iSceneManager.h"
#include "iObject.h"
#include "iTexture.h"
#include "iResources.h"

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
			bg = Object::Instantiate<Player>(eLayerType::Background);

			SpriteRender* sr = bg->AddComponent<SpriteRender>();

			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"Beach BG");
			sr->SetTexture(bg);
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