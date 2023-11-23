#pragma once
#include "iEntity.h"

using namespace std;

namespace in
{
	class Resource abstract : public Entity
	{
	public:
		Resource(eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const wstring& path) = 0;
		// 순수 가상함수 -> 실제 메모리 할당 불가 -> 상속 받아서만 사용 가능

		const wstring& GetPath() { return mPath; }
		void SetPath(const wstring& path) { mPath = path; }
	
	private:
		const eResourceType mType;
		wstring mPath;
	};
}

// 개별 리소스는 Resource를 상속받아 사용