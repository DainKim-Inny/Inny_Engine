#pragma once
#include "..\\Inny_Engine_SOURCE\\iResources.h"
#include "..\\Inny_Engine_SOURCE\\iTexture.h"

namespace in
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Title BG", L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Main cloud.png");
		Resources::Load<graphics::Texture>(L"Play BG", L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Standard Farm.png");
		Resources::Load<graphics::Texture>(L"Beach BG", L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Beach Overview.png");
		Resources::Load<graphics::Texture>(L"Logo", L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Logo No Background.png");
		Resources::Load<graphics::Texture>(L"Chicken", L"C:\\Users\\kimda\\source\\repos\\Inny_Engine\\Resource\\Chicken White.png");
	}
}
