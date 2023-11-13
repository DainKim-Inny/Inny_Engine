#pragma once
#include "..\\Inny_Engine_SOURCE\\\iScene.h"

namespace in
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Updata() override;
		void LateUpdata() override;
		void Render(HDC hdc) override;

	private:
	};
}

