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
		Resources::Load<graphics::Texture>(L"Logo", L"..\\Resource\\Logo.png");
		Resources::Load<graphics::Texture>(L"LoadButton", L"..\\Resource\\Load.png");
		Resources::Load<graphics::Texture>(L"NewButton", L"..\\Resource\\New.png");
		Resources::Load<graphics::Texture>(L"ExitButton", L"..\\Resource\\Exit.png");
		Resources::Load<graphics::Texture>(L"Bird", L"..\\Resource\\Bird.bmp");
		Resources::Load<graphics::Texture>(L"Chicken", L"..\\Resource\\Chicken White.png");
		Resources::Load<graphics::Texture>(L"Chicken2", L"..\\Resource\\Chicken White .bmp");
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resource\\map.png");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resource\\Player.bmp");
	}
}
