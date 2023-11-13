#pragma once
#include "CommonInclude.h"

using namespace std;

// ������ϴ� ��� ��ü�� Entity ��ӹް��ϱ�

namespace in
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();  // ��� �ޱ� ���� ���� �Լ� ����

		void SetName(const wstring& name) { mName = name; }
		wstring& GetName() { return mName; }

	private:
		wstring mName;
	};
}