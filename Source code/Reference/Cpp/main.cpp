#include "..\headers\game.h"

int WINAPI wWinMain( HINSTANCE h_instance, HINSTANCE prev_instance, LPWSTR command_line, int window_display_options )
{
	UNREFERENCED_PARAMETER( prev_instance ); 
	UNREFERENCED_PARAMETER( command_line );

	Game game( h_instance );

    return 0;
}
