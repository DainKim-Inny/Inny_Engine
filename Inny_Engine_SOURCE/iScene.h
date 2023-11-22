#pragma once
#include "iEntity.h"
#include "iGameObject.h"
#include "iLayer.h"

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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const eLayerType type);
		Layer* GetLayer(const eLayerType type) { return mLayers[(UINT)type]; }

	private:
		void CreateLayers();

	private:
		vector<Layer*> mLayers;
	};
}