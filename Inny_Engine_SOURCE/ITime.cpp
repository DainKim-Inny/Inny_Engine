#include "ITime.h"

namespace in
{
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurrentFrequency = {};
	float Time::DeltaTimeValue = 0.01f;  

	void Time::Initialize()
	{
		// 현재 내 CPU 고유 진동수
		QueryPerformanceFrequency(&mCpuFrequency);

		// 프로그램 시작 했을 때 현재 진동 수
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void Time::Updata()
	{
		// Applicatio Run() 한번 진행될 때 마다 진동 수 알고 싶음 -> 프로그램 시작 시 진동수 / CPU의 고유 진동수
		QueryPerformanceCounter(&mCurrentFrequency);

		// (현재 진동수 - 이전 진동수)
		float differenceFrequency
			= static_cast<float>(mCurrentFrequency.QuadPart - mPrevFrequency.QuadPart);  // C++ 스타일로 float로 형 변환

		DeltaTimeValue = differenceFrequency / static_cast<float>(mCpuFrequency.QuadPart);

		mPrevFrequency.QuadPart = mCurrentFrequency.QuadPart;  // 이전 진동수를 현재 진동수로 바꿔줌
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;  // 프레임 측정

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %f", fps);  // 프레임 출력

		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}

}