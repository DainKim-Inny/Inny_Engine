#pragma once

namespace in
{
	enum class eLayerType
	{
		None,
		Background,
		Logo,
		Tree,
		NPC,
		Player,
		Max = 16
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}