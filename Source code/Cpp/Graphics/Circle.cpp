#include "Source code/Hpp/Graphics/Circle.hpp"

Circle::Circle()
{
}

void Circle::set_position( Point const & position )
{
    position_ = position;
}

Point Circle::get_position() const
{
    return position_;
}