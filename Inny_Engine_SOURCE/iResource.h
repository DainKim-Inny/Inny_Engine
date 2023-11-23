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
		// ���� �����Լ� -> ���� �޸� �Ҵ� �Ұ� -> ��� �޾Ƽ��� ��� ����

		const wstring& GetPath() { return mPath; }
		void SetPath(const wstring& path) { mPath = path; }
	
	private:
		const eResourceType mType;
		wstring mPath;
	};
}

// ���� ���ҽ��� Resource�� ��ӹ޾� ���