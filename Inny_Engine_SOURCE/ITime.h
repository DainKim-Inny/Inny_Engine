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
		static LARGE_INTEGER mCpuFrequency; // LARGE �ڷ��� : 8����Ʈ �ڷ���. �ش� CPU�� ���� ������ ����
		static LARGE_INTEGER mPrevFrequency;  // �� ������ ���� ������
		static LARGE_INTEGER mCurrentFrequency;  // ���� ������
		static float DeltaTimeValue;  // ������ -> �ð� ��ȭ�� ���� ���� ����
	};
}