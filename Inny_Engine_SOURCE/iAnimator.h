#pragma once
#include "iComponent.h"
#include "iAnimation.h"

using namespace std;

namespace in
{
	class Animator : public Component
	{
	public:

		struct Event
		{
			void operator=(function<void()> func)
			{
				mEvent = move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent;
			}

			function<void()> mEvent;
		};

		struct Events
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;
		};

		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);

		Animation* FindAnimation(const wstring& name);
		void PlayAnimation(const wstring& name, bool loop = true);

		bool IsComplete() { return mActiveAnimation->IsComplete(); }

	private:
		map<wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;

		map<wstring, Event*> mEvents;
	};
}