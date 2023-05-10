#pragma once

#include <d2d1.h>

#include "Source code/Hpp/Graphics/Direct2D/Image.hpp"
#include "Source code/Hpp/Time/Timer.hpp"

#include <list>

class Sprite : public Image , public Timer
{
    public:
    
        void update(); 

    private:
        
        double current_frame_time {};
};
