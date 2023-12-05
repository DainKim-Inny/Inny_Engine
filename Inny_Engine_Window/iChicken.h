#pragma once
#include "..\\Inny_Engine_SOURCE\\iGameObject.h"

namespace in
{
	class Chicken : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
