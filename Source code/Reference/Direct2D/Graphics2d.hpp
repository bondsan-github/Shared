#pragma once

#include "Custom types.hpp"
#include "Graphics\vertex.hpp"

#include <windows.h>
#include <wrl/client.h> // ComPtr
using Microsoft::WRL::ComPtr;

#pragma comment( lib , "d2d1.lib" )

#include <d2d1_3.h>

//struct monitor {};
//struct page {};

class Application;

class GraphicsD2D
{
    private:

        Application & application;

        HRESULT                         result { E_FAIL };

        //https://learn.microsoft.com/en-us/windows/win32/direct2d/devices-and-device-contexts
        ComPtr< ID2D1Factory7 >         factory {};
        HWND                            window  {};
        ComPtr< ID2D1HwndRenderTarget > page    {};

        D2D1_PIXEL_FORMAT page_format { DXGI_FORMAT_B8G8R8A8_UNORM , 
                                        D2D1_ALPHA_MODE_UNKNOWN }; 
                                        //D2D1_ALPHA_MODE_STRAIGHT };
        
        PAINTSTRUCT   paint {};

        D2D1_COLOR_F  colour_clear { 0.5f , 0.5f , 0.5f , 1.0f };
        //D2D1_SIZE_F page_size    { 0.0f , 0.0f };
        //float       page_dips    { 0.0f };
        //D2D1_SIZE_F page_dpi     { 0.0f , 0.0f };
       
        void reset();
        bool reset_page();
        void resize();

    public:

        GraphicsD2D( Application & application );
        //~GraphicsD2D();
            
        //void set_window( HWND in_window ) { }
        void initialise();// HWND in_window );
        void draw_begin();
        void draw_end();
        //void draw();
            
        ID2D1Factory *          get_factory() { return factory.Get(); }
        ID2D1HwndRenderTarget * get_page() { return page.Get(); }
        D2D_SIZE_F              get_size_dips();
        //D2D_SIZE_U              get_size_pixels();
        D2D_SIZE_U              get_screen_size();
        D2D_SIZE_F              get_dpi();

}; // class graphics_d2d


 //ID2D1SolidColorBrush  & get_brush_solid( D2D1::ColorF in_colour = D2D1::ColorF::Yellow );
            /*
            ID2D1StrokeStyle      & get_stroke_style( stroke_cap_style  in_cap_start   = stroke_cap_style::flat  ,
                                                 stroke_cap_style  in_cap_dash    = stroke_cap_style::flat  ,
                                                 stroke_cap_style  in_cap_end     = stroke_cap_style::flat  ,
                                                 stroke_line_join  in_line_join   = stroke_line_join::round ,
                                                 float             in_miter_limit = 1.0f                    ,
                                                 stroke_dash_style in_dash_style  = stroke_dash_style::dash ,
                                                 float             in_dash_offset = 1.0f                    );
 /*
         class sheet
         {
            enum class request_type { window_ptr , size };

            using window_ptr = ID2D1HwndRenderTarget *;
            using size    = D2D1_SIZE_F;

            window_ptr _sheet {};
            size    _size  {};

            public:

            sheet( window_ptr const in_sheet = {} , const size in_size = {} )
            : _sheet( in_sheet ) , _size( in_size )
            {}

            size    size()    const { return _size; }
            window_ptr window_ptr() const { return _sheet; }
         };
         */

         //vector< sheet > sheets {};