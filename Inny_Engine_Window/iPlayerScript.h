#pragma once
#include "..\\Inny_Engine_SOURCE\\iScript.h"

namespace in
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			UsingAxes,  // ������
			UsingHoes,  // ȣ����
			UsingScythe,  // ����
			UsingPickaxes // �����
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void move();
		void usingAxes();
		//void usingHoes();
		//void usingScythe();
		//void usingPickaxes();

	private:
		eState mState;
		class Animator* mAnimator;

	};

}
