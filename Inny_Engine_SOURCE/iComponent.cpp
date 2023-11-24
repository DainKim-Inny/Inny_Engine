#include "iComponent.h"

namespace in
{
	Component::Component(eComponentType type)
		: mType(type)
	{
	}

	Component::~Component()
	{
	}
	
	void Component::Initialize()
	{
	}
	
	void Component::Update()
	{
	}
	
	void Component::LateUpdate()
	{
	}
	
	void Component::Render(HDC hdc)
	{
	}
}