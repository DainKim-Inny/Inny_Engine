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
		HBITMAP mBackBitmap;  // �߰� DC ������ֱ�

		UINT mWidth;  // �ػ� ����
		UINT mHeight;  // �ػ� ����
			
		GameObject mPlayer;
		GameObject_Red mPlayer_Red;
		GameObject_Shoot* mShoot[1000] = {};
		int Counting;
	};
}