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
			scene->Initialize();  // ������ ��ġ �ٸ��� ������ �ʱ�ȭ

			mScene.insert(make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const wstring& name)
		{
			map<wstring, Scene*>::iterator iter
				= mScene.find(name);

			if (iter == mScene.end())
			{
				return nullptr;
			}

			mActiveScene = iter->second;

			return iter->second;
		}

		static void Initialize();  // � �� ����ž�
		static void Updata();  // ���� �� ������Ʈ
		static void LateUpdata();
		static void Render(HDC hdc);

	private:
		static map<wstring, Scene*> mScene;  // wstring�� KEY. Tree�� �� ��ü �ֱ�
		static Scene* mActiveScene;  // �����ؾ� �� ���� �ϳ�
	};
}

