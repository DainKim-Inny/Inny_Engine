#pragma once
#include "CommonInclude.h"
#include "iGameObject.h"
#include "iGameObject_Red.h"

namespace in
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Updata();
		void LateUpdata();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		
		GameObject mPlayer;
		GameObject_Red mPlayer_Red;
	};
}

