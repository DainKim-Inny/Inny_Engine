#pragma once
#include "..\\Inny_Engine_SOURCE\\iResources.h"
#include "..\\Inny_Engine_SOURCE\\iTexture.h"

namespace in
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Title BG", L"..\\Resource\\Main cloud.png");
		Resources::Load<graphics::Texture>(L"Play BG", L"..\\Resource\\Standard Farm.png");
		Resources::Load<graphics::Texture>(L"Beach BG", L"..\\Resource\\Beach Overview.png");
		Resources::Load<graphics::Texture>(L"Logo", L"..\\Resource\\Logo No Background.png");
		Resources::Load<graphics::Texture>(L"Chicken", L"..\\Resource\\Chicken White.png");
	}
}
