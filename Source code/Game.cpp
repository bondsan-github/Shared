#include "Game.hpp"

#include "Locate.hpp"
#include "Game states.hpp"

Game::Game()
{
    Locate::game( this );

    //if(
    os.initialise();
    
    if( graphics.initialise() )
    {
        camera.initialise( L"main" );
        camera.set_projection( Projection::orthographic );
        camera.set_position( { 0.0f , 0.0f , 50.0f , 1.0f } );
        //camera.set_target( { 0.0f , 0.0f , 0.0f , 1.0f } );

        timer.initialise();
        timer.start();

        state = new Splash();

        os.message_loop();
    }
    // else error_exit();
}

void Game::update()
{
    timer.tick();
    camera.update();

    State * new_state = state->update( timer.delta() );

    if( new_state not_eq nullptr )
    {
        delete state;
         
        state = new_state;
    }
}

void Game::render()
{
    graphics.frame_begin();

    state->render();

    graphics.frame_end();
}

Game::~Game()
{
    if( state ) delete state;
}
