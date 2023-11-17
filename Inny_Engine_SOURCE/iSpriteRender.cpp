#include "iSpriteRender.h"
#include "iGameObject.h"
#include "iTransform.h"

namespace in
{
	SpriteRender::SpriteRender()
		: mImage(nullptr),
		mWidth(0),
		mHeight(0)
	{
	}

	SpriteRender::~SpriteRender()
	{
	}
	
	void SpriteRender::Initialize()
	{
	}
	
	void SpriteRender::Update()
	{
	}
	
	void SpriteRender::LateUpdate()
	{
	}
	
	void SpriteRender::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	void SpriteRender::ImageLoad(const wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}