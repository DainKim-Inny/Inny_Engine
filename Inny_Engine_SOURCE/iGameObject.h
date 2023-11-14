#pragma once
#include "CommonInclude.h"

namespace in
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Updata();
		virtual void LateUpdata();
		virtual void Render(HDC hdc);

		virtual void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		virtual float GetPositionX() { return mX; }
		virtual float GetPositionY() { return mY; }

	private:
		// 게임 오브젝트의 좌표
		float mX;
		float mY;
	};
}