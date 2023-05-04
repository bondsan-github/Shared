#pragma once

//#include <Windows.h>
#include <vector>

#include <wrl/client.h>
#include <wincodec.h>

#include <string>

#include "Custom types.hpp"
#include "Loging.hpp"

class WICImage //: public Image
{
	public:

		WICImage() { }
		WICImage( const std::wstring & in_filename );

		void load( const std::wstring in_filename );

		uint get_width()  const { return width; }
		uint get_height() const { return height; }

		//const DXGI_FORMAT pixel_format() const { return wic_pixel_format_guid; }

		unsigned char * get_pixels()
		{ 
			return pixels.data();
		}

		//const Pixel_format pixel_format() const { return _pixel_format; }

	private:

		std::vector< unsigned char > pixels;

		HRESULT	result { E_FAIL };

        Microsoft::WRL::ComPtr< IWICImagingFactory > imaging_factory {};
        Microsoft::WRL::ComPtr< IWICBitmapDecoder > bitmap_decoder {};
        Microsoft::WRL::ComPtr< IWICBitmapFrameDecode > bitmap_frame_decode {};

		WICPixelFormatGUID wic_pixel_format_guid {};

        Microsoft::WRL::ComPtr< IWICFormatConverter > format_converter {};

		bool can_convert = false;

        Microsoft::WRL::ComPtr< IWICComponentInfo > component_info {};
        Microsoft::WRL::ComPtr < IWICPixelFormatInfo > pixel_format_info {};

		GUID format_guid {};

		wchar_t	format_name[ 128 ] {};
		uint	chars_read {};

		//Pixel_format pixel_format {};

		uint bits_per_pixel {};

		uint row_byte_pitch {};
		uint size_bytes {};

		uint channel_count {};

		uint frame_count {};

		uint width {};
		uint height {};		
};

/*
struct WIC_to_DXGI
{
    GUID		wic;
    DXGI_FORMAT	format;
};

static WIC_to_DXGI WICFormats[]
{
    { GUID_WICPixelFormat32bppRGBA,	DXGI_FORMAT_R8G8B8A8_UNORM }
};
*/