#pragma once
#include "..\\Inny_Engine_SOURCE\\iSceneManager.h"
#include "iPlayScene.h"
#include "iBeachScene.h"
#include "iTitleScene.h"

namespace in
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<BeachScene>(L"BeachScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
	
		SceneManager::LoadScene(L"BeachScene");
	}
}