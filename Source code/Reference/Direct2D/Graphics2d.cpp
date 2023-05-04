
#include "Graphics\Graphics D2D.hpp"
//#include "..\headers\write_d2d.h"
//#include "Operating system\MSWindows.hpp"
#include "Application.hpp"
#include "Logging.hpp"

GraphicsD2D::GraphicsD2D( Application & application )
: application{ application }
{
    
}

void GraphicsD2D::initialise()
{
    window = application.get_gui().get_window();

    D2D1_FACTORY_OPTIONS factory_options {};

    factory_options.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;

    result = D2D1CreateFactory( D2D1_FACTORY_TYPE_SINGLE_THREADED ,
                       factory_options ,
                       factory.ReleaseAndGetAddressOf() );

    if( FAILED( result ) ) error_exit( L"Unable to create D2D factory." , result );

    reset();
}

void GraphicsD2D::reset()
{
    reset_page();
}

//GraphicsD2D::~GraphicsD2D() {}

// help: your first direct2d program
bool GraphicsD2D::reset_page()
{
    // If the window creation has not finished.
    if( not window )
    {
        window = application.get_gui().get_window();

        return false;
    }

    // If a render target has not been created.
    if( not page )
    {
        //https://learn.microsoft.com/en-us/windows/win32/direct2d/supported-pixel-formats-and-alpha-modes

        // TODO: enable render target transparency
        D2D1_RENDER_TARGET_PROPERTIES render_properties {};

        render_properties.type        = D2D1_RENDER_TARGET_TYPE_DEFAULT; //D2D1_RENDER_TARGET_TYPE_HARDWARE
        render_properties.usage       = D2D1_RENDER_TARGET_USAGE_NONE;
        render_properties.minLevel    = D2D1_FEATURE_LEVEL_DEFAULT;
        render_properties.pixelFormat = page_format;
        render_properties.dpiX        = 0.0;
        render_properties.dpiY        = 0.0;

        RECT client_size {};

        GetClientRect( window , & client_size );

        D2D_SIZE_U client_area { client_size.right - client_size.left ,
                                 client_size.bottom - client_size.top };

        D2D1_HWND_RENDER_TARGET_PROPERTIES window_properties {};

        window_properties.hwnd           = window;
        window_properties.pixelSize      = client_area;
        window_properties.presentOptions = D2D1_PRESENT_OPTIONS_NONE;

        result = factory->CreateHwndRenderTarget( render_properties ,
                                                  window_properties ,
                                                  & page );

        if( FAILED( result ) ) error_exit( L"Unable to create swap chain." , result );
    }

    return true;
}
   

void GraphicsD2D::draw_begin()
{
    // If a valid render target is available.
    if( reset_page() )
    {
        D2D1_SIZE_F renderTargetSize = page->GetSize();

        page->BeginDraw();

        page->SetTransform( D2D1::Matrix3x2F::Identity() );

        //page->Clear( colour_clear );
        page->Clear( { 0,0,0,1 } );

        /*
        if( hr == D2DERR_RECREATE_TARGET )
        {
            hr = S_OK;
            DiscardDeviceResources();
        }*/
    }
}

void GraphicsD2D::draw_end()
{
    if( page )
        page->EndDraw();
}

D2D_SIZE_U GraphicsD2D::get_screen_size()
{
    return { page->GetPixelSize().width , page->GetPixelSize().height };
}

D2D1_SIZE_F GraphicsD2D::get_size_dips()
{
    //D2D1_SIZE_F size = 
    return { page->GetSize().width , page->GetSize().height };
}

D2D_SIZE_F GraphicsD2D::get_dpi()
{
    D2D_SIZE_F page_dpi{ 0.0f , 0.0f };

    page->GetDpi( &page_dpi.width , &page_dpi.height );

    return page_dpi;
}

// void draw_page( page in_page );

void GraphicsD2D::resize()
{
    RECT rectangle;

    GetClientRect( window , & rectangle);

    D2D1_SIZE_U size = D2D1::SizeU( rectangle.right - rectangle.left,
                                    rectangle.bottom - rectangle.top );

    //if( page ) 
    page->Resize( size );

    //calculate_layout();   

    InvalidateRect( window , 0 , false );
}

        //page_dpi          dpi         = get_dpi();
        //dimensions        size_dips   = get_size_dips();
        //page_dimensions   size_pixels = get_size_pixels();
        // width  = 3840 , dpi.x = 240, dips.width = 1536 // (desktop 3840 x 2160 )
        // dips = pixels / ( dpi / 96.0 );
        //float center_x = in_position_center.x;// * size_dips.width; 
        //float center_y = in_position_center.y;// * size_dips.height; 
        //const float width       = in_size.width;// / dpi.width; 
        //const float height      = in_size.height;// / dpi.height;
        //const float width_half  = width  / 2.0f;
        //const float height_half = height / 2.0f;
        //const float margin      = 5.0f;
        //float top    = center_y - height_half - margin;
        //float right  = center_x + width_half  + margin;
        //float bottom = center_y + height_half + margin;
        //float left   = center_x - width_half  - margin;


    /*
    brush_solid_pointer GraphicsD2D::get_brush_solid( colours in_colour)
    {
        brush_solid_pointer brush_solid{};
        get_page()->CreateSolidColorBrush( in_colour , brush_solid.ReleaseAndGetAddressOf());
        return brush_solid.Get();
    }
    */

    //pass page
    /*
    ID2D1SolidColorBrush & GraphicsD2D::brush_solid( colours in_colour )
    {
        brush_solid_pointer brush_solid {};
        HRESULT result;
        result = page->CreateSolidColorBrush( in_colour , brush_solid.ReleaseAndGetAddressOf() );

        return ** brush_solid.ReleaseAndGetAddressOf();
    }
    */

 /*
    ComPtr< stroke_style > GraphicsD2D::style( colours in_colour )
    {
        ComPtr< stroke_style > style {};
        //factory->CreateStrokeStyle( style_properties , )
    }
    */

    /*
    stroke_style_pointer GraphicsD2D::get_stroke_style( stroke_cap_style  in_cap_start   ,
                                                     stroke_cap_style  in_cap_dash    ,
                                                     stroke_cap_style  in_cap_end     ,
                                                     stroke_line_join  in_line_join   ,
                                                     float             in_miter_limit ,
                                                     stroke_dash_style in_dash_style  ,
                                                     float             in_dash_offset )
    {
        stroke_style_pointer    style{};
        stroke_style_properties properties{};
        vector< float >         dashes{ 2.0f, 2.0f };// length of each dash and space in the pattern.
        // [0] dash length
        // [1] space length ...

        properties.startCap    = static_cast< D2D1_CAP_STYLE >( in_cap_start );
        properties.endCap      = static_cast< D2D1_CAP_STYLE >( in_cap_dash );
        properties.dashCap     = static_cast< D2D1_CAP_STYLE >( in_cap_end );
        properties.lineJoin    = static_cast< D2D1_LINE_JOIN >( in_line_join );
        properties.miterLimit  = in_miter_limit;
        properties.dashStyle   = static_cast< D2D1_DASH_STYLE >( in_dash_style );
        properties.dashOffset  = in_dash_offset;


        //properties.cap_start   = in_cap_start;
        //properties.dash_start  = in_dash_start;
        //properties.end_start   = in_end_start;
        //properties.line_join   = in_line_join;
        //properties.miter_limit = in_miter_limit;
        //properties.dash_style  = in_dash_style;
        //properties.dash_offset = in_dash_offset;


        factory->CreateStrokeStyle( properties ,
                                    dashes.data() ,
                                    static_cast< uint >( dashes.size() ),
                                    style.ReleaseAndGetAddressOf() );
        return style;
    }
    */