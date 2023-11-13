#include "iSceneManager.h"

using namespace std;

namespace in
{
	map<wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
	}

	void SceneManager::Updata()
	{
		mActiveScene->Updata();
	}
	
	void SceneManager::LateUpdata()
	{
		mActiveScene->LateUpdata();
	}
	
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}