#include "iGameObject.h"
#include "iInput.h"

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
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdata()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		// 督空事 持失
		HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, OldBrush);
		DeleteObject(BlueBrush);
	}
}