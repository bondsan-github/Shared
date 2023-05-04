#include "Game.hpp"

//int WINAPI wWinMain( HINSTANCE instance_handle , HINSTANCE prev_instance, LPWSTR command_line, int window_display_options )
int WINAPI wWinMain( _In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPWSTR lpCmdLine , _In_ int nCmdShow )
{
    // Initialize COM apartment threaded. 
    // This is the recommended way to initialize COM for the UI thread.
    HRESULT result  = CoInitializeEx( nullptr , COINITBASE_MULTITHREADED );

    if( FAILED( result ) ) return 1;

    {
        Game game;
        game.run();
    }

    CoUninitialize();

    return 0;
}
