#pragma once
#include "CommonInclude.h"

using namespace std;

// 디버깅하는 모든 객체가 Entity 상속받게하기

namespace in
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();  // 상속 받기 위해 가상 함수 선언

		void SetName(const wstring& name) { mName = name; }
		wstring& GetName() { return mName; }

	private:
		wstring mName;
	};
}