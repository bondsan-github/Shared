#pragma once

#include "Operating system/MSWindows.hpp"
#include "Graphics/Direct2D/Graphics2D.hpp"
#include "Time/Timer.hpp"
#include "Graphics/Size.hpp"

class Application : public MSWindows , public Graphics , public Timer
{
    protected:
        
        //Input     input { *this };
        //Audio     audio;

    private:

    public:
        
        Application();

        void initialise( Size in_client_size = {} );
        void run();

        virtual ~Application() = default;

        virtual void update() = 0;
        virtual void render() = 0;

        // cannot call virtual functions in a constructor or destructor 
        // as any derived objects have not been constructed.
};