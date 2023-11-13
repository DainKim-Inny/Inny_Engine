#include "iPlayScene.h"
#include "iGameObject.h"

using namespace std;

namespace in
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}
	
	void PlayScene::Initialize()
	{
		for (int i = 0; i < 100; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj);
		}
	}
	
	void PlayScene::Updata()
	{
		Scene::Updata();
	}
	
	void PlayScene::LateUpdata()
	{
		Scene::LateUpdata();
	}
	
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}