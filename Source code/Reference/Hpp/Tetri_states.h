#pragma once

// tetri_states.h
//template < typename type >

class Tetrimino;

namespace line_em_up 
{
	namespace Tetrimino
	{
	}
}

class State //abstract
{
	public:
		virtual State * update( Tetrimino & actor , double time_delta ) = 0;

		// virtual void input() {};
		// virtual void update() {};
};

class Falling : public State//< Tetrimino >
{
	public:
		virtual State * update( Tetrimino & actor , double time_delta );
};

class Next : public State
{
	public:
		virtual State * update( Tetrimino & actor , double time_delta );
};

//class Game_actor
//{
//	public:
//
//		virtual void rotate( Rotation in_rotation ) = 0;
//};
