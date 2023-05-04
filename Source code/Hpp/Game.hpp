#pragma once

#include "Operating system\MSWindows.hpp"
#include "Timer.hpp"
#include "Graphics\Graphics.hpp"
#include "Graphics\Camera.hpp"
#include "Input\Input.hpp"
#include "Graphics\Colour.hpp"

// tmxlite
#include <Map.hpp>

class State;

class Game 
{
    private:

        Timer     timer;
        MSWindows gui;
        Graphics  graphics;
        Camera    camera;
        Input     input;
        // audio
        //tmx::Map  map;
               
        State *  state {};

    public:

        Game();
        ~Game();
        
        void update();
        void render();

        Colour red   { 1.0f , 0.0f , 0.0f , 1.0f };
        Colour green { 0.0f , 1.0f , 0.0f , 1.0f };
        Colour blue  { 0.0f , 0.0f , 1.0f , 1.0f };
};

// * Before public release make sure Symbols are removed ! *