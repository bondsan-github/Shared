#include <iostream>
#include <memory>
#include <map>

using namespace std;

// finite state machine
// find traffic light example

// FSM
class state abstract
{
	public:
		virtual void enter() = 0;
		virtual void exit() = 0;

	private:
		state * next ;
		state * previous;
};

//states { idle , moving , falling , rotating , sliding , locked , rotating };

// falling -> press B -> rotate CW

enum class Rotation { clock_wise , counter_clock_wise };

class Game_actor
{
	public:

		void rotate( Rotation in_rotation) 
		{
			// if in_rotation == Rotation::clock_wise 
			//		cout "\n clock wise " <<  Rotation::clock_wise ? 
			// else
			//		cout "\n counter clock wise " 
			cout << "\n rotate";
		}
};

// command pattern
class Command abstract
{
	public:

		virtual void execute( Game_actor & actor ) = 0;
};

class Rotate : public Command
{
	public:

		Rotate( const Rotation in_rotation ) : rotation_direction( in_rotation )
		{}

		virtual void execute( Game_actor & actor ) override
		{ 
			actor.rotate( rotation_direction );
		}

	private:
		Rotation rotation_direction;
};

class Drop : public Command
{
	public:

		virtual void execute( Game_actor & actor ) override
		{
			cout << "\nDrop";
		}
};

class Input_handler
{
	public:
	
		Input_handler()
		{
			// Methods to bind commands...
			command_map.insert( make_pair( 'z' , new Rotate( Rotation::clock_wise ) ) );
			command_map.insert( make_pair( 'x' , new Rotate( Rotation::counter_clock_wise ) ) );
		}

		Command * handle_input( const char in_char )
		{
			//

			const auto result = command_map.find( in_char );

			if( result != command_map.end() ) return result->second;
			else return nullptr;

			//try
			//{
			//	command_map.at( in_char )->execute();
			//}
			//catch( std::out_of_range & exception ) 
			//{
			//	cout << "\n command not implemented";
			//}

			//if( in_char == 'x' ) key_x->execute();
			//else if( in_char == 'z' ) key_z->execute();
		}

	private:

		map< char , Command * > command_map;
};

int main()
{
	Game_actor actor;
	Input_handler keyboard;

	Command * command = nullptr;

	char input = '*';

	while( input != 'q' )
	{
		cout << "\nPress key for command : z or x\n";
		cin >> input;

		//
		command = keyboard.handle_input( input );

		if( command ) command->execute( actor );
	}

	return 0;
}