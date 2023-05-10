#pragma once

#include <memory>

#include "State.hpp"
#include "Graphics\Quad.hpp"
#include "Graphics\Icosahedron.hpp"
#include "Input\Input.hpp"

class Splash : public State
{
    public:

        Splash();

        virtual State * update( double time_delta );
        
        virtual void render();

        virtual void notification( Key event );
        //virtual void notification( std::variant<Key, Timer> event ) override;

        virtual ~Splash();

        /*virtual void input(const Command & command) { if( command == input_any_button ) }*/

    private:

        Quad logo { L".\\Data\\Graphics\\sunset.jpg" };
        //Quad logo { 1.0f , 1.0f , Colour( 1.0f , 0.2f , 0.2f , 1.0f ) };
        Icosahedron sphere {0};

        double time_elapsed {};
        double display_durration = 60;

        bool skip { false } , finished {false};
};

class Menu : public State
{
    virtual State * update( double time_delta );
    virtual void    notification( Key event );
    virtual void    render();
};

class Intro : public State
{
    /*
    virtual State * update( double time_delta ) override;
    virtual void notification( Key event ) override;
    virtual void render() override;
    */
};