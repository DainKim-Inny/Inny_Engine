#pragma once
#include "..\Inny_Engine_SOURCE\iScene.h"

namespace in
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Updata() override;
		void LateUpdata() override;
		void Render(HDC hdc) override;

	private:

	};
}