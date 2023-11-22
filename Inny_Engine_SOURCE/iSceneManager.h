#pragma once
#include "iScene.h"

using namespace std;

namespace in
{
	class SceneManager
	{
	public:  // ��ü�� �������ϱ� ������ static

		template <typename T>
		static Scene* CreateScene(const wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;
			scene->Initialize();  // ������ ��ġ �ٸ��� ������ �ʱ�ȭ

			mScene.insert(make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const wstring& name);

		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initialize();  // � �� ����ž�
		static void Update();  // ���� �� ������Ʈ
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static map<wstring, Scene*> mScene;  // wstring�� KEY. Tree�� �� ��ü �ֱ�
		static Scene* mActiveScene;  // �����ؾ� �� ���� �ϳ�
	};
}