#include "iTitleScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "IInput.h"
#include "iPlayScene.h"
#include "iSceneManager.h"
#include "iObject.h"

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
			bg = Object::Instantiate<Player>(eLayerType::Background, Vector2(0.0f, 0.0f));
			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Main cloud.png");
		}

		{
			logo = Object::Instantiate<Player>(eLayerType::Logo, Vector2(300.0f, 300.0f));
			SpriteRender* sr = logo->AddComponent<SpriteRender>();
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Logo No Background.png");
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