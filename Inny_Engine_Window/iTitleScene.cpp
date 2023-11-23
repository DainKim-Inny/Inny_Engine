#include "iTitleScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "IInput.h"
#include "iPlayScene.h"
#include "iSceneManager.h"
#include "iObject.h"
#include "iTexture.h"
#include "iResources.h"

using namespace std;

namespace in
{
	TitleScene::TitleScene()
		: bg(nullptr), logo(nullptr)
	{

	}

	TitleScene::~TitleScene()
	{

	}
	
	void TitleScene::Initialize()
	{
		{
			bg = Object::Instantiate<Player>(eLayerType::Background);

			SpriteRender* sr = bg->AddComponent<SpriteRender>();

			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"Title BG");
			sr->SetTexture(bg);
		}

		{
			logo = Object::Instantiate<Player>(eLayerType::Logo, Vector2(300.0f, 200.0f));

			SpriteRender* sr = logo->AddComponent<SpriteRender>();

			graphics::Texture* logo = Resources::Find<graphics::Texture>(L"Logo");
			sr->SetTexture(logo);
		}

		Scene::Initialize();
	}
	
	void TitleScene::Update()
	{
		Scene::Update();
	}
	
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}

	void TitleScene::OnEnter()
	{
		Scene::OnEnter();
	}
	
	void TitleScene::OnExit()
	{
		Scene::OnExit();
	}
}