#pragma once
#include "CommonInclude.h"

using namespace std;

namespace in
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER mCpuFrequency; // LARGE 자료형 : 8바이트 자료형. 해당 CPU의 고유 진동수 저장
		static LARGE_INTEGER mPrevFrequency;  // 한 프레임 이전 진동수
		static LARGE_INTEGER mCurrentFrequency;  // 현재 진동수
		static float DeltaTimeValue;  // 진동수 -> 시간 변화를 위해 변수 선언
	};
}