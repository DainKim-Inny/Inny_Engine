#include "iTitleScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "IInput.h"
#include "iPlayScene.h"
#include "iSceneManager.h"

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
			bg = new Player();

			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"Title_TR");

			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->SetName(L"Title_SR");
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Main cloud.png");

			AddGameObject(bg, eLayerType::Background);
		}

		{
			logo = new Player();

			Transform* tr = logo->AddComponent<Transform>();
			tr->SetPos(Vector2(300, 300));
			tr->SetName(L"Title_TR");

			SpriteRender* sr = logo->AddComponent<SpriteRender>();
			sr->SetName(L"Title_SR");
			sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Logo No Background.png");

			AddGameObject(logo, eLayerType::Logo);
		}
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