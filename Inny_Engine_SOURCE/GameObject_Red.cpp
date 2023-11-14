#include "iGameObject_Red.h"

namespace in
{
	GameObject_Red::GameObject_Red()
	{
	}

	GameObject_Red::~GameObject_Red()
	{

	}

	void GameObject_Red::Updata()
	{
		GameObject::Updata();
	}

	void GameObject_Red::LateUpdata()
	{
		GameObject::LateUpdata();
	}

	void GameObject_Red::Render(HDC hdc)
	{
		// »¡°£ ¿ø »ý¼º
		HBRUSH RedBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, RedBrush);

		Ellipse(hdc, GetPositionX(), GetPositionY(), 50 + GetPositionX(), 50 + GetPositionY());

		SelectObject(hdc, OldBrush);
		DeleteObject(RedBrush);
	}
}