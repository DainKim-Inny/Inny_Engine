#pragma once
#include "..\\Inny_Engine_SOURCE\\iSceneManager.h"
#include "iPlayScene.h"

namespace in
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		// SceneManager::CreateScene<EndScene>(L"EndScene");
		// SceneManager::CreateScene<TitleScene>(L"TitleScene");
	
		SceneManager::LoadScene(L"PlayScene");
	}
}