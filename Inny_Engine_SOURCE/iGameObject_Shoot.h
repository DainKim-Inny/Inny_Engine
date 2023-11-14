#pragma once
#include "CommonInclude.h"
#include "iGameObject.h"

namespace in
{
	class GameObject_Shoot : public GameObject
	{
	public:
		GameObject_Shoot();
		~GameObject_Shoot();

		void Updata() override;
		void LateUpdata() override;
		void Render(HDC hdc) override;

	private:
	};
}