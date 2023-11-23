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
		HBITMAP mBackBitmap;  // �߰� DC ������ֱ�

		UINT mWidth;  // �ػ� ����
		UINT mHeight;  // �ػ� ����

		//GameObject_Red mPlayer_Red;
		//GameObject_Shoot* mShoot[1000] = {};
		//int Counting;
		//GameObject mPlayer;

		// vector <GameObject*> mGameObject;  // GameOjbect vectorȭ

		// Application�� Scene�� �����ְ� Scene�� GameObject�� ������
		vector<Scene*> mScenes;
	};
}