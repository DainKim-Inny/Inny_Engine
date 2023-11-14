#include "iTitleScene.h"
#include "iGameObject.h"
#include "iGameObject_Red.h"

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
			GameObject_Red* obj = new GameObject_Red();
			obj->SetPosition(rand()%500, rand()%500);
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