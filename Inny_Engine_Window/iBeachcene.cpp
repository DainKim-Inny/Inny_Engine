#include "iBeachScene.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "iInput.h"
#include "iSceneManager.h"
#include "iObject.h"
#include "iTexture.h"
#include "iResources.h"
#include "iPlayerScript.h"
#include "iCamera.h"
#include "iRenderer.h"
#include "iTitleScene.h"

using namespace std;

namespace in
{
	BeachScene::BeachScene()
		: bg(nullptr)
	{

	}

	BeachScene::~BeachScene()
	{

	}
	
	void BeachScene::Initialize()
	{
		GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, Vector2(820.0f, 470.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		{
			bg = Object::Instantiate<Player>(eLayerType::Background);

			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->SetSize(Vector2(1.3f, 1.5f));

			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"Beach BG");
			sr->SetTexture(bg);
		}

		Scene::Initialize();
	}
	
	void BeachScene::Update()
	{
		Scene::Update();
	}
	
	void BeachScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	
	void BeachScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Beach Scene";
		TextOut(hdc, 0, 0, str, 11);
	}

	void BeachScene::OnEnter()
	{
		Scene::OnEnter();
	}
	
	void BeachScene::OnExit()
	{
		Scene::OnExit();
	}
}