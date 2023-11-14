#pragma once
#include "..\\Inny_Engine_SOURCE\iScene.h"

namespace in
{
	class EndScene : public Scene
	{
	public:
		EndScene();
		~EndScene();

		void Initialize() override;
		void Updata() override;
		void LateUpdata() override;
		void Render(HDC hdc) override;

	private:

	};

}