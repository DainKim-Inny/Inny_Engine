#include "iTexture.h"
#include "iApplication.h"

// �ش� ���� ������ �������� �˸��� Ű���� extern ����
extern in::Application application;

namespace in::graphics
{
	Texture::Texture()
		: Resource(eResourceType::Texture)
	{
	}

	Texture::~Texture()
	{
	}
	
	HRESULT Texture::Load(const wstring& path)
	{
		wstring ext = path.substr(path.find_last_of(L".") + 1);

		// bmp �� ��
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png")  // png �� ��
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());

			if (mImage == nullptr)
				return S_FALSE;

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}

		return S_OK;
	}
}