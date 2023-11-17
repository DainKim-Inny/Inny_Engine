#pragma once
#include "..\\Inny_Engine_SOURCE\iScene.h"

namespace in
{
	class BeachScene : public Scene
	{
	public:
		BeachScene();
		~BeachScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};

}