#pragma once

const float origin_x = 0.0f;
const float origin_y = 0.0f;

enum class Direction { left , right , down };
enum class Rotation { clock_wise , counter_clock_wise };

const float layer_playfield = 0.0f;
const float layer_block = -1.0f;

// namespace line_em_up {}
class Tetri_centre
{
	public:

		Tetri_centre() 
		{

		}

		Tetri_centre( const uint in_block , const uint in_vertex0 , const uint in_vertex1 )
			: block( in_block ) , vertex0( in_vertex0 ) , vertex1( in_vertex1 )
		{
			//assert( block >= 0 );
			//assert( vertex0 >= 0 );
			//assert( vertex1 >= 0 );
		}

		//Tetri_centre() {}; // = delete;

		

		uint get_block()   const { return block; }
		uint get_vertex_0() const { return  vertex0; }
		uint get_vertex1() const { return vertex1; }

	private:
		uint block = 0u;
		uint vertex0 = 0u;
		uint vertex1 = 0u;

};

//enum class Graphic_layers { playfield = 0 , block };

//typedef struct Graphic_layers
//{
//	const float playfield	= 0.0f;
//	const float block		= -1.0f;
//} Graphic_layers;

//class Graphic_layers
//{
//	public:
//	const float playfield = 0.0f;
//	const float block = -1.0f;
//};
//
//Graphic_layers graphic_layers;