 #pragma once
#include "..\Inny_Engine_SOURCE\iScene.h"

namespace in
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* bg;
		class Player* mChicken;
		class Player* mPlayer;
	};
}

