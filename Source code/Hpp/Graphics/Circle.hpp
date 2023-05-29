#pragma once

#include "Source code/Hpp/Graphics/Point.hpp"

class Circle
{
    private:

        int   radius_   {};
        Point position_ {};

    public:

        Circle();

        void set_position( Point const & position );
        Point get_position() const;
};
