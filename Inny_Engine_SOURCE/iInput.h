#pragma once
#include "CommonInclude.h"

using namespace std;

namespace in
{
	// ���ڸ� ���ڷ� �ٲ��ִ� ����
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

		// Ű���� state�� ���� �Լ�
		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; };
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; };
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; };  // ������ �ð� ��ŭ

	private:
		static vector<Key> mKeys; // ��� Ŭ���� �ȿ����� ������ �����ؾ��ϹǷ� ���� ������ ����
		// eKeyState mState[] = eKeyState::Up; Ű�� input�� ���� ���� ���� 
	};
}