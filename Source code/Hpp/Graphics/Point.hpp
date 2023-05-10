#pragma once

#include <d2d1.h>

class Point
{
    private:

        int x_ {};
        int y_ {};

    public:

        Point();
        Point( int x , int y );

        void x( int x );
        void y( int y );

        int  x() const;
        int  y() const;

        D2D1_RECT_F operator + ( D2D1_RECT_F & in_rect );
        Point       operator - ( float in_value );
        Point &     operator -= ( float in_value );
        
                    operator D2D1_POINT_2F ();
                    operator D2D1_SIZE_F ();
};
