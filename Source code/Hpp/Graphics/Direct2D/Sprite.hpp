#pragma once

#include <d2d1.h>

#include "Graphics/Image.hpp"
#include "Timer.hpp"

#include <list>

class Sprite : public Image , public Timer
{
    public:
    
        void update(); 

    private:
        
        double current_frame_time {};
};
