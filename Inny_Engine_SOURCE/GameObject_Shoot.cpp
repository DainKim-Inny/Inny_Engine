#include "iGameObject_Shoot.h"
#include "iInput.h"
#include "iApplication.h"

namespace in
{
	GameObject_Shoot::GameObject_Shoot()
		: mX(0.0f), mY(0.0f), mSpeed(0.0f)
	{

	}

	GameObject_Shoot::~GameObject_Shoot()
	{

	}

	void GameObject_Shoot::Updata()
	{
		mX += 0.5f;
	}

	void GameObject_Shoot::LataUpdata()
	{

	}

	void GameObject_Shoot::Render(HDC hdc)
	{
		HBRUSH GreenBrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, GreenBrush);

		Rectangle(hdc, mX, mY, 50 + mX, 50 + mY);

		SelectObject(hdc, OldBrush);
		DeleteObject(GreenBrush);
	}
}