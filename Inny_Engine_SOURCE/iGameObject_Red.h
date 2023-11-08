#pragma once
#include "CommonInclude.h"

namespace in
{
	class GameObject_Red
	{
	public:
		GameObject_Red();
		~GameObject_Red();

		void Updata();
		void LateUpdata();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		// ���� ������Ʈ�� ��ǥ
		float mX;
		float mY;
	};
}
