#include "iGameObject.h"

namespace in
{
	GameObject::GameObject()
		: mX(0.0f), mY(0.0f)
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Updata()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdata()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		// 파란색 생성
		HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, OldBrush);
		DeleteObject(BlueBrush);
	}
}