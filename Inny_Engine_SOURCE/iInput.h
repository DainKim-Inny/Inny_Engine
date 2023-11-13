#pragma once
#include "CommonInclude.h"

using namespace std;

namespace in
{
	// 숫자를 문자로 바꿔주는 문법
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Up, Down, Space,
		End
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Updata();

		// 키보드 state에 따른 함수
		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; };
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; };
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; };  // 누르는 시간 만큼

	private:
		static vector<Key> mKeys; // 어느 클래스 안에서도 접근이 가능해야하므로 정적 변수로 선언
		// eKeyState mState[] = eKeyState::Up; 키의 input에 대한 상태 저장 
	};
}