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
	
	void Scene::Update()
	{
		//for (int i = 0; i < mGameObjects.size(); i++)
		//{
		//	mGameObjects[i]->Updata();
		//}
		// ���� ��� for��
		for (GameObject* gameObj : mGameObjects)  // mGameObjects index �ϳ��� �޾Ƽ� gameObj�� �ִ´�
		{
			gameObj->Update();
		}
	}
	
	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects) 
		{
			gameObj->LateUpdate();
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