#include "ITime.h"

namespace in
{
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurrentFrequency = {};
	float Time::DeltaTimeValue = 0.01f;  

	void Time::Initialize()
	{
		// ���� �� CPU ���� ������
		QueryPerformanceFrequency(&mCpuFrequency);

		// ���α׷� ���� ���� �� ���� ���� ��
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void Time::Updata()
	{
		// Applicatio Run() �ѹ� ����� �� ���� ���� �� �˰� ���� -> ���α׷� ���� �� ������ / CPU�� ���� ������
		QueryPerformanceCounter(&mCurrentFrequency);

		// (���� ������ - ���� ������)
		float differenceFrequency
			= static_cast<float>(mCurrentFrequency.QuadPart - mPrevFrequency.QuadPart);  // C++ ��Ÿ�Ϸ� float�� �� ��ȯ

		DeltaTimeValue = differenceFrequency / static_cast<float>(mCpuFrequency.QuadPart);

		mPrevFrequency.QuadPart = mCurrentFrequency.QuadPart;  // ���� �������� ���� �������� �ٲ���
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;  // ������ ����

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %f", fps);  // ������ ���

		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}

}