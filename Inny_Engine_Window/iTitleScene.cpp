#include "iTitleScene.h"
#include "iGameObject.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"

using namespace std;

namespace in
{
	TitleScene::TitleScene()
	{

	}

	TitleScene::~TitleScene()
	{

	}
	
	void TitleScene::Initialize()
	{
		Player* Title = new Player();

		Transform* tr = Title->AddComponent<Transform>();
		tr->SetPos(Vector2(300, 300));
		tr->SetName(L"Title_TR");

		SpriteRender* sr = Title->AddComponent<SpriteRender>();
		sr->SetName(L"Title_SR");
		sr->ImageLoad(L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Logo No Background.png");

		AddGameObject(Title);
	}
	
	void TitleScene::Update()
	{
		Scene::Update();
	}
	
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}