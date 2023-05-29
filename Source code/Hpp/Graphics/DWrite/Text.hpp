#pragma once

#include "Source code/Hpp/Custom types.hpp"
#include "Source code/Hpp/Graphics/Vertex.hpp"

#include <d2d1.h>
#include <dwrite.h>

#include <string>
using std::wstring;

#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

#include "Source code/Hpp/Custom types.hpp"
#include "Source code/Hpp/Graphics/DWrite/Write factory.hpp"
#include "Source code/Hpp/Graphics/Direct2D/Drawable2D.hpp"
#include "Source code/Hpp/Graphics/Direct2D/Rectangle2D.hpp"

class Text : public Write_factory , public Drawable2D
{
    private:
       
        ComPtr< IDWriteTextFormat >    format     {};
        ComPtr< ID2D1SolidColorBrush > brush_font {};
        ComPtr< IDWriteTextLayout >    layout     {};
        //ComPtr <IDWriteFontCollection> collection {};

        wstring               content_ {};
            
        //vertex                position_center   { 10.0f , 10.0f        }; // dips
        Point                 position_         { 0.0f , 0.0f          }; // in dips
            
        wstring               font_locale       { L"en-us" }; // en-GB
        wstring               font_face         { L"Times New Roman"   }; // font family
        float                 font_size         { 15.0f                }; // * dpi? // MS "size * 96.0f/72.0f"
        D2D1::ColorF          font_colour       { D2D1::ColorF::Black       };
        float                 font_opacity      { 1.0f                 };
        DWRITE_FONT_STYLE     font_style        { DWRITE_FONT_STYLE_NORMAL };
        DWRITE_FONT_WEIGHT    font_weight       { DWRITE_FONT_WEIGHT_NORMAL };
        DWRITE_FONT_STRETCH   font_stretch      { DWRITE_FONT_STRETCH_NORMAL };
            
        // collection
        // family
        // spacing
        // trimming
        // wrapping
        // alignment_vertical
        // alignment_horizontal
        // direction_reading
        // direction_flow

        D2D1_SIZE_F  layout_size_ { 150.0 , 150.0 };

        Rectangle2D  border {};

        bool         border_show          { true };
        float        border_line_width    { 2.0f };
        D2D1::ColorF border_line_colour   { D2D1::ColorF::Yellow };
        float        border_corner_radius { 1.0f };
        float        border_inner_margin  { 5.0f };
            
    private:
            
        void reset();
        void reset_format();
        void reset_layout();
        void reset_brush();
        void reset_border();
            
        D2D1_SIZE_F get_layout_size() const;
        float       get_width_half() const ;
        float       get_height_half() const ;
        //planes    middle_planes();

    public:

            Text();
            Text( wstring const & in_content );
            ~Text();

        void set( wstring const & in_content );
        void add( wstring const & in_string ); // add to end // concatenate

        void set_locale( wstring const & in_locale );
        void set_face( wstring const & in_font_face );
        void set_size( float in_font_size );
        void set_colour( D2D1::ColorF const & in_font_colour );
        void set_opacity( float in_font_opacity );
        void set_style( DWRITE_FONT_STYLE in_font_style );
        void set_weight( DWRITE_FONT_WEIGHT in_font_weight );
        void set_stretch( DWRITE_FONT_STRETCH in_font_stretch );

        void set_position( Point const & in_position );
        void set_layout_size( D2D1_SIZE_F const & in_layout_size );

        void show_border( bool in_show_border );
        //void set_rectangle_radius( float in_radius );
        //void set_rectangle_line_colour( D2D1::ColorF in_colour );
        //void set_rectangle_line_width( float in_width );
        //void set_font_options( font_options in_font_options );

        wstring get_content() const { return content_; }
        wstring get_locale() const { return font_locale; }
        //font_options options();
            
        Point  get_position() const;

        //Rectangle get_layout_size();
        float top() const;
        float right() const;
        float left() const;
        float bottom() const;
        float width() const ;
        float height() const ;

        //rectangle_edge_middles get_middle_vertices();
        //rectangle            get_formated_rectangle();

        void draw();

}; // class text

//https://learn.microsoft.com/en-us/windows/win32/direct2d/improving-direct2d-performance#use-a-multithreaded-device-context
//https://learn.microsoft.com/en-us/windows/win32/directwrite/rendering-by-using-direct2d

/*
class Text_metrics : public DWRITE_TEXT_METRICS
{
    public:

        Text_metrics() { reset(); }

        void reset()
        {
            left         = 0.0f; // in device independant pixels
            top          = 0.0f;
            width        = 0.0f;
            widthIncludingTrailingWhitespace = 0.0f;
            height       = 0.0f;
            layoutWidth  = 0.0f;
            layoutHeight = 0.0f;
            maxBidiReorderingDepth = 0u;
            lineCount    = 0u;
        }
};
*/