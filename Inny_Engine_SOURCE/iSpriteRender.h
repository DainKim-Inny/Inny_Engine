#pragma once
#include "iEntity.h"
#include "iComponent.h"
#include "iTexture.h"

using namespace std;

namespace in
{
	class SpriteRender : public Component
	{
	public:
		SpriteRender();
		~SpriteRender();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(Vector2 size) { mSize = size; }

	private:
		graphics::Texture* mTexture;
		Vector2 mSize;
	};

}
