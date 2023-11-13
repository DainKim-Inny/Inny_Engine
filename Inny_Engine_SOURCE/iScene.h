#pragma once
#include "iEntity.h"
#include "iGameObject.h"

using namespace std;

namespace in
{
	class Scene : public Entity // 이름은 다 사용되니까 상속받아서 사용
	{
	public:
		Scene();
		~Scene();

		virtual	void Initialize();
		virtual void Updata();
		virtual void LateUpdata();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		vector<GameObject*> mGameObjects;
	};
}
