#include "iApplication.h"
#include "iInput.h"
#include "ITime.h"
#include "iGameObject_Shoot.h"

namespace in
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr),
		mWidth(0),
		mHeight(0),
		mBackHdc(nullptr),
		mBackBitmap(nullptr),
		Counting(0)
	{

	}

	Application::~Application()
	{

	}
		

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height };

		// 내 윈도우의 작업 영역 크기를 rect로 조절하겠다
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		// rect로 조정한 윈도우를 새로 셋팅
		SetWindowPos(mHwnd, nullptr, 0, 0
			, mWidth
			, mHeight, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가리킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Updata();
		LateUpdata();
		Render();
	}

	void Application::Updata()
	{
		Input::Updata();
		Time::Updata();

		mPlayer.Updata();

		if (Input::GetKeyDown(eKeyCode::Space))
		{
			GameObject_Shoot* shoot = new GameObject_Shoot;
			mShoot[Counting] = shoot;
			mShoot[Counting]->SetPosition(mPlayer.GetPositionX()+200, mPlayer.GetPositionY()+150);
			Counting++;
		}

		for (int i = 0; i < Counting; i++)
		{
			if (mShoot[i] != 0)
			{
				mShoot[i]->Updata();
			}
		}
	}

	void Application::LateUpdata()
	{

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		for (int i = 0; i < Counting; i++)
		{
			if (mShoot[i] != 0)
			{
				mShoot[i]->Render(mBackHdc);
			}
		}

		// 백버퍼에 있는 것을 원본 버퍼에 복사(그려준다)
		BitBlt(mHdc, 0, 0, mWidth, mHeight
			, mBackHdc, 0, 0, SRCCOPY);
	}
}