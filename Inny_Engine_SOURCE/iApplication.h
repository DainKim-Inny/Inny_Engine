#pragma once
#include "CommonInclude.h"
#include "iGameObject.h"
#include "iScene.h"

using namespace std;

namespace in
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		
		void Update();
		void LateUpdata();
		void Render();

		HDC GetHdc() { return mHdc; }

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;  // 추가 DC 만들어주기

		UINT mWidth;  // 해상도 저장
		UINT mHeight;  // 해상도 저장

		//GameObject_Red mPlayer_Red;
		//GameObject_Shoot* mShoot[1000] = {};
		//int Counting;
		//GameObject mPlayer;

		// vector <GameObject*> mGameObject;  // GameOjbect vector화

		// Application이 Scene을 갖고있고 Scene이 GameObject를 가진다
		vector<Scene*> mScenes;
	};
}