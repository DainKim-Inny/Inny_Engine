#pragma once
#include "iEntity.h"
#include "CommonInclude.h"
#include "iGameObject.h"

using namespace std;

namespace in
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		vector<GameObject*> mGameObjects;
	};
}

