#pragma once
#include "CommonInclude.h"
#include "iGameObject.h"
#include "iGameObject_Red.h"
#include "iGameObject_Shoot.h"

namespace in
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Updata();
		void LateUpdata();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;  // 추가 DC 만들어주기

		UINT mWidth;  // 해상도 저장
		UINT mHeight;  // 해상도 저장
			
		GameObject mPlayer;
		GameObject_Red mPlayer_Red;
		GameObject_Shoot* mShoot[1000] = {};
		int Counting;
	};
}