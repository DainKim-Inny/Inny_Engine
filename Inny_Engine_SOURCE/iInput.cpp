#include "iInput.h"
#include "iApplication.h"

extern in::Application application;

using namespace std;

namespace in
{
	vector<Input::Key> Input::mKeys = {};
	Vector2 Input::mMousePosition = Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SPACE,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON
	};

	void in::Input::Initialize()
	{
		for (int i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void in::Input::Update()
	{
		if (GetFocus())
		{
			for (int i = 0; i < mKeys.size(); i++)
			{
				// 키가 눌렸는지 아닌지
				if (GetAsyncKeyState(ASCII[i]) & 0x8000)  // 키가 눌렸을 때
				{
					if (mKeys[i].bPressed == true)
					{
						mKeys[i].state = eKeyState::Pressed;
					}
					else
					{
						mKeys[i].state = eKeyState::Down;
					}

					mKeys[i].bPressed = true;
				}
				else  // 키가 안 눌렸다
				{
					if (mKeys[i].bPressed == true)
					{
						mKeys[i].state = eKeyState::Up;
					}
					else
					{
						mKeys[i].state = eKeyState::None;  // 키가 안 눌렸는데 아직 안 눌렸음 
					}

					mKeys[i].bPressed = false;
				}
			}

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);

		mMousePosition.x = mousePos.x;
		mMousePosition.y = mousePos.y;
	}

	void Input::clearKeys()
	{
		for (Key& key : mKeys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state == eKeyState::None;

			key.bPressed = false;
		}
	}

}