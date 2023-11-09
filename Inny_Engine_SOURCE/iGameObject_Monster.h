#pragma once
#include "CommonInclude.h"

namespace in
{
	class GameObject_Monster
	{
	public:
		GameObject_Monster();
		~GameObject_Monster();

		void Updata();
		void LataUpdata();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX;
		float mY;
		float mSpeed;
	};
}