#include "iTitleScene.h"
#include "iPlayer.h"
#include "iTransform.h"
#include "iSpriteRender.h"
#include "IInput.h"
#include "iPlayScene.h"
#include "iSceneManager.h"
#include "iObject.h"
#include "iTexture.h"
#include "iResources.h"
#include "iPlayerScript.h"
#include "iBirdScript.h"
#include "iCamera.h"
#include "iRenderer.h"

using namespace std;

namespace in
{
	TitleScene::TitleScene()
		: bg(nullptr), Logo(nullptr), NewButton(nullptr), LoadButton(nullptr)
		, ExitButton(nullptr), Bird(nullptr)
	{

	}

	TitleScene::~TitleScene()
	{

	}
	
	void TitleScene::Initialize()
	{
		GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, Vector2(850.0f, 470.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		{
			bg = Object::Instantiate<Player>(eLayerType::Background);

			SpriteRender* sr = bg->AddComponent<SpriteRender>();

			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"Title BG");
			sr->SetTexture(bg);
		}

		{
			Logo = Object::Instantiate<Player>(eLayerType::Logo, Vector2(550.0f, 200.0f));

			SpriteRender* sr = Logo->AddComponent<SpriteRender>();
			sr->SetSize(Vector2(1.3f, 1.3f));

			graphics::Texture* Logo = Resources::Find<graphics::Texture>(L"Logo");
			sr->SetTexture(Logo);
		}

		{
			NewButton = Object::Instantiate<Player>(eLayerType::Button, Vector2(550.0f, 500.0f));

			SpriteRender* sr = NewButton->AddComponent<SpriteRender>();
			sr->SetSize(Vector2(2.0f, 2.0f));

			graphics::Texture* NewButton = Resources::Find<graphics::Texture>(L"NewButton");
			sr->SetTexture(NewButton);
		}

		{
			LoadButton = Object::Instantiate<Player>(eLayerType::Button, Vector2(750.0f, 500.0f));

			SpriteRender* sr = LoadButton->AddComponent<SpriteRender>();
			sr->SetSize(Vector2(1.9f, 1.9f));

			graphics::Texture* LoadButton = Resources::Find<graphics::Texture>(L"LoadButton");
			sr->SetTexture(LoadButton);
		}

		{
			ExitButton = Object::Instantiate<Player>(eLayerType::Button, Vector2(950.0f, 500.0f));

			SpriteRender* sr = ExitButton->AddComponent<SpriteRender>();
			sr->SetSize(Vector2(1.8f, 1.8f));

			graphics::Texture* ExitButton = Resources::Find<graphics::Texture>(L"ExitButton");
			sr->SetTexture(ExitButton);
		}

		{
			Bird = Object::Instantiate<Player>(eLayerType::Background, Vector2(1550.0f, 400.0f));

			SpriteRender* sr = Bird->AddComponent<SpriteRender>();
			sr->SetSize(Vector2(2.0f, 2.0f));

			Bird->AddComponent<BirdScript>();

			graphics::Texture* Bird = Resources::Find<graphics::Texture>(L"Bird");
			sr->SetTexture(Bird);
		}



		Scene::Initialize();
	}
	
	void TitleScene::Update()
	{
		Scene::Update();
	}
	
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}

	void TitleScene::OnEnter()
	{
		Scene::OnEnter();
	}
	
	void TitleScene::OnExit()
	{
		Scene::OnExit();
	}
}