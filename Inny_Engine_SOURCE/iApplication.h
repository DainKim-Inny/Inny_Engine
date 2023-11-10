#pragma once
#include "CommonInclude.h"
#include "iGameObject.h"
#include "iGameObject_Red.h"
#include "iGameObject_Monster.h"

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
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
			
		GameObject mPlayer;
		GameObject_Red mPlayer_Red;
		GameObject_Monster mPlayer_Monster;
	};
}