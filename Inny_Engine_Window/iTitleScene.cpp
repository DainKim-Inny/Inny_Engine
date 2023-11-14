#include "iTitleScene.h"
#include "iGameObject.h"

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
		for (int i = 0; i < 2; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPosition(500, 500);
			AddGameObject(obj);
		}
	}
	
	void TitleScene::Updata()
	{
		Scene::Updata();
	}
	
	void TitleScene::LateUpdata()
	{
		Scene::LateUpdata();
	}
	
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}