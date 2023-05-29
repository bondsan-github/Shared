#pragma once

#include "Source code/Hpp/Graphics/Circle.hpp"
#include "Source code/Hpp/Graphics/Direct2D/Drawable2D.hpp"

class Circle2D : public Circle , public Drawable2D
{
    private:

        float        line_width_  {};
        D2D1::ColorF line_colour_ { D2D1::ColorF( 1.0 , 1.0 , 1.0 , 1.0 ) };

        ComPtr< ID2D1SolidColorBrush > brush_{};
        ComPtr< ID2D1StrokeStyle1 >    style_{};

    public:

        //draw();
};
