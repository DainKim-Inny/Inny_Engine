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
		// 범위 기반 for문
		for (GameObject* gameObj : mGameObjects)  // mGameObjects index 하나씩 받아서 gameObj에 넣는다
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