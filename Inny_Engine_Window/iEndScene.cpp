#include "iEndScene.h"
#include "iGameObject.h"
#include "iGameObject_Shoot.h"

namespace in
{
	EndScene::EndScene()
	{

	}

	EndScene::~EndScene()
	{

	}
	
	void EndScene::Initialize()
	{
		GameObject_Shoot* obj = new GameObject_Shoot();
		obj->SetPosition(100, 100);
		AddGameObject(obj);
	}
	
	void EndScene::Updata()
	{
		Scene::Updata();
	}
	
	void EndScene::LateUpdata()
	{
		Scene::LateUpdata();
	}
	
	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}