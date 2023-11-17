#pragma once
#include "iEntity.h"
#include "iGameObject.h"

using namespace std;

namespace in
{
	class Scene : public Entity // �̸��� �� ���Ǵϱ� ��ӹ޾Ƽ� ���
	{
	public:
		Scene();
		~Scene();

		virtual	void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		vector<GameObject*> mGameObjects;
	};
}