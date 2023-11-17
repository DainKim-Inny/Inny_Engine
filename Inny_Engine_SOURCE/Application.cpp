#include "iApplication.h"
#include "iInput.h"
#include "ITime.h"
#include "iSceneManager.h"

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

		// �� �������� �۾� ���� ũ�⸦ rect�� �����ϰڴ�
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		// rect�� ������ �����츦 ���� ����
		SetWindowPos(mHwnd, nullptr, 0, 0
			, mWidth
			, mHeight, 0);
		ShowWindow(mHwnd, true);

		// ������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		Input::Initialize();
		Time::Initialize();

		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdata();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		SceneManager::Update();
	}

	void Application::LateUpdata()
	{

	}

	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight
			, source, 0, 0, SRCCOPY);
	}

	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);

		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}
}