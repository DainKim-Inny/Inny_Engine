#pragma once
#include "iScene.h"

using namespace std;

namespace in
{
	class SceneManager
	{
	public:  // 전체에 쓰여야하기 때문에 static

		template <typename T>
		static Scene* CreateScene(const wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();  // 씬마다 위치 다르기 때문에 초기화

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

		static void Initialize();  // 어떤 씬 만들거야
		static void Updata();  // 만든 씬 업데이트
		static void LateUpdata();
		static void Render(HDC hdc);

	private:
		static map<wstring, Scene*> mScene;  // wstring이 KEY. Tree에 씬 전체 넣기
		static Scene* mActiveScene;  // 실행해야 할 씬은 하나
	};
}

