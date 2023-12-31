#pragma once
#include "iComponent.h"
#include "iGameObject.h"
#include "iLayer.h"
#include "iScene.h"
#include "iSceneManager.h"
#include "iTransform.h"

namespace in
{

	class Object
	{
	public:
		template<typename T>
		static T* Instantiate(eLayerType type)
		{
			T* gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template<typename T>
		static T* Instantiate(eLayerType type, Vector2 position)
		{
			T* gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPosition(position);

			return gameObject;
		}
	};
}
