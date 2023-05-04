#pragma once

#include <map>
#include <string>

#include <d2d1_3.h>

using uchar  = unsigned char;  //  8 bits
using ushort = unsigned short; // 16 bits
using uint   = unsigned int;   // 32 bits
using ulong  = unsigned long;  // long same as int
//using string = std::wstring;

//using vertex = vertex_rgba_uv;

template< typename Type >
static void set_name( Type com , wchar_t const * name )
{
    com->SetPrivateData( __uuidof( com ) , static_cast< uint >( wcslen( name ) * 2 ) , name );
}

struct Range
{
    long minimum { 0 };
    long maximum { 0 };

    //range() {}
    //range( const long & in_minimum , const long & in_maximum ) : minimum( in_minimum ) , maximum( in_maximum ) {}
};

class Size
{
    private:

        int width_  { };
        int height_ { };

    public:

        Size() 
        {};

        Size( int width , int height ) : width_( width ) , height_( height ) 
        {}

        bool operator == ( Size & size )
        {
            return size.width_ == width_ and size.height_ == height_;
        }

        bool operator != ( Size & size )
        {
            return size.width_ != width_ or size.height_ != height_;
        }

        operator D2D1_SIZE_U ()
        {
            return { static_cast< uint >( width_ ) , static_cast< uint >( height_ ) };
        }

        void width( int width ) { width_ = width; }
        void height( int height ) { height_ = height; }

        int  width() const { return width_; }
        int  height() const { return height_; }
};

//template< typename type >
// == for floats -> within range
//using size_f = Size<float>;

class Point
{
    private:
    
        int x_ { };
        int y_ { };

    public:

        Point() {};
        explicit Point( int x , int y ) : x_( x ) , y_( y ) { }
        
        void x( int x ) { x_ = x; }
        void y( int y ) { y_ = y; }
        int  x() const { return x_; }
        int  y() const { return y_; }

        D2D1_RECT_F operator + ( D2D1_RECT_F & in_rect )
        {
            return { static_cast<float>( x_ )  ,
                     static_cast< float >( y_ ) ,
                     static_cast< float >( x_ ) + in_rect.right ,
                     static_cast< float >( y_ ) + in_rect.bottom };
        }
};

inline bool operator < ( RECT const & lhs , RECT const & rhs)
{
    return ( lhs.right - lhs.left ) * ( lhs.bottom - lhs.top ) < 
           ( rhs.right - rhs.left ) * ( rhs.bottom - rhs.top );
        
}

//using      result                  = HRESULT;
//enum class factory_type            { force_dword = -1 , single_thread , multiple_threads };

//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
// WinUser.h

const std::map< std::wstring , unsigned int > inputs_english
{
    { L"0" , 0x30u } ,
    { L"1" , 0x31u } ,
    { L"2" , 0x32u } ,
    { L"3" , 0x33u } ,
    { L"4" , 0x34u } ,
    { L"5" , 0x35u } ,
    { L"6" , 0x36u } ,
    { L"7" , 0x37u } ,
    { L"8" , 0x38u } ,
    { L"9" , 0x39u } ,
    // 0x3a
    // ...
    // 0x40
    { L"a" , 0x41 } ,
    { L"b" , 0x42 } ,
    { L"c" , 0x43 } ,
    { L"d" , 0x44 } ,
    { L"e" , 0x45 } ,
    { L"f" , 0x46 } ,
    { L"g" , 0x47 } ,
    { L"h" , 0x48 } ,
    { L"i" , 0x49 } ,
    { L"j" , 0x4a } ,
    { L"k" , 0x4b } ,
    { L"l" , 0x4c } ,
    { L"m" , 0x4d } ,
    { L"n" , 0x4e } ,
    { L"o" , 0x4f } ,
    { L"p" , 0x50 } ,
    { L"q" , 0x51 } ,
    { L"r" , 0x52 } ,
    { L"s" , 0x53 } ,
    { L"t" , 0x54 } ,
    { L"u" , 0x55 } ,
    { L"v" , 0x56 } ,
    { L"w" , 0x57 } ,
    { L"x" , 0x58 } ,
    { L"y" , 0x59 } ,
    { L"z" , 0x5a } ,
    //{ L"Left Windows" , VK_LWIN } ,
};

/*
D2D_POINT_2F operator + ( const D2D_POINT_2F & in_point_left , const D2D_POINT_2F & in_point_right )
{
    return { in_point_left.x + in_point_right.x , in_point_left.y + in_point_right.y };
}*/

//using      paint_structure         = PAINTSTRUCT;
//using size = D2D1_SIZE_F;
//using      colours                 = D2D1::ColorF;
/*
class colours : public D2D1::ColorF //_D3DCOLORVALUE
{
public:
    friend bool operator not_eq ( const D2D1::ColorF & in_left , const D2D1::ColorF & in_right )
    {
        return { in_left.r == in_right.r and
                    in_left.g == in_right.g and 
                    in_left.b == in_right.b };
    }
};
*/

//enum class alpha_mode { force_dword = -1 , unknown , pre_multiplied , straight , ignore };
//enum class style { solid , dots , dashes ,
    
//using      write_factory           = IDWriteFactory;
//enum class write_factory_type      { shared , isolated };
//using      renderer_parameters     = IDWriteRenderingParams;

//using      font_collection         = IDWriteFontCollection;
//using      font_collection_pointer = ComPtr< font_collection >;
//using      font_family             = IDWriteFontFamily;
//using      font_collection_names   = IDWriteLocalizedStrings;
//using      font_weight             = DWRITE_FONT_WEIGHT;
//using      font_style              = DWRITE_FONT_STYLE;
//using      font_stretch            = DWRITE_FONT_STRETCH;

//using      text_format             = IDWriteTextFormat;
//using      text_format_pointer     = ComPtr< text_format >;
//using      text_layout             = IDWriteTextLayout;
//using      text_layout_pointer     = ComPtr< text_layout >;
//enum class font_style              { normal          , oblique       , italic         };
//enum class font_weight             { light     = 300 , regular = 400 , bold     = 700 };
//enum class font_stretch            { condensed = 3   , normal  = 5   , expanded = 7   };
/*
enum class font_options            { force_dword    = -1 , 
                                        none           =  0 ,
                                        no_snap        =  1 ,
                                        clip           =  2 ,
                                        colour_font    =  4 ,
                                        no_snap_bitmap =  8 };
                                        */
//using      text_metrics            = DWRITE_TEXT_METRICS;
//using      text_analyser           = IDWriteTextAnalyzer;

//using      rectangle               = D2D_RECT_F;
//using      rounded_rectangle       = D2D1_ROUNDED_RECT;
//using      dimensions              = D2D_SIZE_F;

/*
struct rectangle_edge_middles
{
    vertex top    {};
    vertex right  {};
    vertex bottom {};
    vertex left   {};
};

struct planes
{
    float horizontal{};
    float vertical{};
};
*/


//const vector< wstring > raw_device_type_text{ L"mouse" , L"keyboard" , L"human interface device" , L"unknown type" };
/*  template< typename page_type = page_for_window >
class page
{
    private:
        ComPtr< page_type >      page_ptr{};
};   */