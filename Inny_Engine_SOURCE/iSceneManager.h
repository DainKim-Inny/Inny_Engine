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
			mActiveScene = scene;
			scene->Initialize();  // 씬마다 위치 다르기 때문에 초기화

			mScene.insert(make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const wstring& name);

		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initialize();  // 어떤 씬 만들거야
		static void Update();  // 만든 씬 업데이트
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static map<wstring, Scene*> mScene;  // wstring이 KEY. Tree에 씬 전체 넣기
		static Scene* mActiveScene;  // 실행해야 할 씬은 하나
	};
}