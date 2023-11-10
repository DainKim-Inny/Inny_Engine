#include "iApplication.h"
#include "iInput.h"
#include "ITime.h"

namespace in
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr),
		mWidth(0),
		mHeight(0),
		mBackHdc(nullptr),
		mBackBitmap(nullptr)
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
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top, 0);
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
		//mPlayer_Red.Updata();
		//mPlayer_Monster.Updata();
	}

	void Application::LateUpdata()
	{

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		//mPlayer_Red.Render(mHdc);
		//mPlayer_Monster.Render(mHdc);

		// 백버퍼에 있는 것을 원본 버퍼에 복사(그려준다)
		BitBlt(mHdc, 0, 0, mWidth, mHeight
			, mBackHdc, 0, 0, SRCCOPY);
	}
}