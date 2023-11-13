#include "iScene.h"

namespace in
{
	Scene::Scene()
		: mGameObjects{}
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}
	
	void Scene::Updata()
	{
		//for (int i = 0; i < mGameObjects.size(); i++)
		//{
		//	mGameObjects[i]->Updata();
		//}
		// ���� ��� for��
		for (GameObject* gameObj : mGameObjects)  // mGameObjects index �ϳ��� �޾Ƽ� gameObj�� �ִ´�
		{
			gameObj->Updata();
		}
	}
	
	void Scene::LateUpdata()
	{
		for (GameObject* gameObj : mGameObjects) 
		{
			gameObj->LateUpdata();
		}
	}
	
	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects) 
		{
			gameObj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}