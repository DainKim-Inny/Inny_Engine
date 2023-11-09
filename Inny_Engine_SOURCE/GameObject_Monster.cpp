#include "iGameObject_Monster.h"

namespace in
{
	GameObject_Monster::GameObject_Monster()
		: mX(0.0f), mY(0.0f), mSpeed(0.0f)
	{

	}

	GameObject_Monster::~GameObject_Monster()
	{

	}

	void GameObject_Monster::Updata()
	{
		if (mY <= 0 || mX <= 0)
		{
			mSpeed = 0.01f;
		}
		else if (500 <= 50+mY || 1120 <= 50+mX) 
		{
			mSpeed = -0.01f;
		}

		mX += mSpeed;
		mY += mSpeed;
	}

	void GameObject_Monster::LataUpdata()
	{

	}

	void GameObject_Monster::Render(HDC hdc)
	{
		HBRUSH GreenBrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, GreenBrush);

		Rectangle(hdc, 10 + mX, 10 + mY, 50 + mX, 50 + mY);

		SelectObject(hdc, OldBrush);
		DeleteObject(GreenBrush);
	}
}