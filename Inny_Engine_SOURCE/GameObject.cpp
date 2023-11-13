#include "iGameObject.h"
#include "iInput.h"
#include "ITime.h"
#include "iGameObject_Shoot.h"

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
		const int speed = 100.0f;

		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
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