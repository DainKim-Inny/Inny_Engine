#include "iGameObject_Red.h"

namespace in
{
	GameObject_Red::GameObject_Red()
		: mX(0.0f), mY(0.0f)
	{

	}

	GameObject_Red::~GameObject_Red()
	{

	}

	void GameObject_Red::Updata()
	{
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}
	}

	void GameObject_Red::LateUpdata()
	{

	}

	void GameObject_Red::Render(HDC hdc)
	{
		// »¡°£ ¿ø »ý¼º
		HBRUSH RedBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, RedBrush);

		Ellipse(hdc, 200 + mX, 200 + mY, 400 + mX, 400 + mY);

		SelectObject(hdc, OldBrush);
		DeleteObject(RedBrush);
	}
}