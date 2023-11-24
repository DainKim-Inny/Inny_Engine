#pragma once

namespace in
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		Background,
		Logo,
		Button,
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