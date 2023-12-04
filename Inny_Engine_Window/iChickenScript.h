#pragma once
#include "..\\Inny_Engine_SOURCE\\iScript.h"

namespace in
{
	class ChickenScript : public Script
	{
	public:
		enum class eChickenState
		{
			SitDown,
			Walk,
			Sleep,
			Relex,
			Eat
		};

		ChickenScript();
		~ChickenScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void sitDown();
		void move();

	private:
		eChickenState mState;
		class Animator* mAnimator;
	};
}