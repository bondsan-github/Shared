#pragma once

//#include <d3d11.h>
#include "d2d1_3.h"

#include <wrl/client.h> // ComPtr
using Microsoft::WRL::ComPtr;

//#include <wincodec.h>

class Drawable
{
    protected:

        //static inline ComPtr< ID2D1HwndRenderTarget > target {};
        static inline ComPtr< ID2D1DeviceContext > context_2d {};


		//static inline ID3D11Device * device3d {};
        //static inline ID2D1DeviceContext * context2d {};
};