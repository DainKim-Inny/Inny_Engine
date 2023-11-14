#pragma once
#include "CommonInclude.h"
#include "iGameObject.h"

namespace in
{
	class GameObject_Red : public GameObject
	{
	public:
		GameObject_Red();
		~GameObject_Red();

		void Updata() override;
		void LateUpdata() override;
		void Render(HDC hdc) override;

	private:

	};
}
