#include "iApplication.h"

namespace in
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr)
	{

	}

	Application::~Application()
	{

	}
		

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);
	}

	void Application::Run()
	{
		Updata();
		LateUpdata();
		Render();

	}

	void Application::Updata()
	{
		mPlayer.Updata();
		mPlayer_Red.Updata();
		mPlayer_Monster.Updata();
	}

	void Application::LateUpdata()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
		mPlayer_Red.Render(mHdc);
		mPlayer_Monster.Render(mHdc);
	}
}