#pragma once

#include "Operating system\MSWindows.hpp"
#include "Time\Timer.hpp"
#include "Graphics\Direct2D\Graphics 2d.hpp"

class Application : public MSWindows , public Graphics2d , public Timer
{
    protected:
        
        //Input     input { *this };
        //Audio     audio;

    private:

    public:
        
        Application();

        void initialise( Size in_client_size );
        void run();

        virtual ~Application() = default;

        virtual void update() = 0;
        virtual void render() = 0;

        // cannot call virtual functions in a constructor or destructor 
        // as any derived objects have not been constructed.
};