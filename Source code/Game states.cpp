
#include "Game states.hpp"
//#include "Game.hpp"
#include "Locate.hpp"
#include "Operating system/Operating system.hpp"

#include "Graphics/Graphics.hpp"

Splash::Splash()
{
    //logo.position( { 0.0f, 0.0f ,0.0f } );
    logo.scale( { 0.5,0.5,0.5 } );
    //sphere.scale( { 5,5,5 } );


    Locate::input().add_observer( this );
}

Splash::~Splash()
{
    Locate::input().remove_observer( this );
}

//void Splash::notification( std::variant<Key, Timer> key )
void Splash::notification( Key key )
{
    using enum Keys;

    if( key == space || key == escape ) skip = true;
}

/*Splash::notification( Time event )
{
    using enum Time::signals;
    if( event == finished ) finished = true;
}*/

State * Splash::update( double time_delta )
{
    time_elapsed += time_delta;

    logo.update( time_delta );
    logo.rotate_y( time_delta );
    
    //sphere.update( time_delta );

    wstring time = L"splash:" + std::to_wstring( time_elapsed );
    SetWindowTextW( Locate::os().window() , time.data() );

    // if finished or skip
    if( time_elapsed > display_durration || skip )// or events.contains( inputs::any )
    {
        return new Menu();
    }

    return nullptr;
}

void Splash::render()
{
    logo.render();
    //sphere.render();
}

State * Menu::update( double time_delta )
{
    //return new Game_intro();
    return nullptr;
}

void Menu::render()
{
    Locate::graphics().clear( { 0.0,1.0,0.0,1.0 } );
}

void Menu::notification( Key key )
{}