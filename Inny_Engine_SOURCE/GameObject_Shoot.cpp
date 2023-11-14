#include "iGameObject_Shoot.h"

namespace in
{
	GameObject_Shoot::GameObject_Shoot()
	{

	}

	GameObject_Shoot::~GameObject_Shoot()
	{

	}

	void GameObject_Shoot::Updata()
	{
		GameObject::Updata();
	}

	void GameObject_Shoot::LateUpdata()
	{
		GameObject::LateUpdata();
	}

	void GameObject_Shoot::Render(HDC hdc)
	{
		HBRUSH GreenBrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, GreenBrush);

		Rectangle(hdc, 100+GetPositionX(), 200+GetPositionY(), 200 + GetPositionX(), 300 + GetPositionY());

		SelectObject(hdc, OldBrush);
		DeleteObject(GreenBrush);
	}
}