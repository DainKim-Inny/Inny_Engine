#pragma once
#include "..\\Inny_Engine_SOURCE\\iScript.h"
#include "..\\Inny_Engine_SOURCE\\iTransform.h"

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

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
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
		void sleep();
		void relex();
		void eat();

		void PlaywalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);

	private:
		eChickenState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
	};
}