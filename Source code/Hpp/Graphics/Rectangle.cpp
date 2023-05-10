#include "Source code/Hpp/Graphics/Rectangle.hpp"
#include "Rectangle.hpp"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle( int x1 , int y1 , int x2 , int y2 )
{   
    top_   = y1;
    left_  = x1;

    right_  = x2;
    bottom_ = y2;
}

void Rectangle::position( int x1 , int y1 , int x2 , int y2 )
{ 
    top_   = y1;
    left_  = x1;

    right_  = x2;
    bottom_ = y2;
}

void Rectangle::position( Point point1 , Point point2 ) 
{ 
    top_  = point1.y();
    left_ = point1.x();

    right_ = point2.x();
    bottom_ = point2.y();
}

void Rectangle::size( int width , int height ) 
{
    bottom_ = height;
    right_  = width;
}

void Rectangle::size( float in_size )
{
    bottom_ = in_size;
    right_  = in_size;
}

void Rectangle::operator = ( D2D1_SIZE_F in_size )
{
    size( in_size.width , in_size.height );
}

void Rectangle::operator + ( float in_size )
{
    top_   -= in_size;
    left_  -= in_size;

    right_  += in_size;
    bottom_ += in_size;
}

Rectangle::operator D2D1_RECT_F()
{
    return { static_cast< float >( left_ ),
             static_cast< float >( top_ ),
             static_cast< float >( right_ ),
             static_cast< float >( bottom_ ) };
}