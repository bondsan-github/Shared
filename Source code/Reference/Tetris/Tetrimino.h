﻿#pragma once

#include "includes.h"

#include <memory>

class Tetrimino //: public State< Tetrimino > //: public Game_actor
{
	public:

		Tetrimino() 
		{

		}

		void create( const vector< XMFLOAT2 >	block_positions_relative ,
					 const Tetri_centre			in_centre ,
					 const wstring				texture_diffuse ,
					 const shared_ptr< Playfield >	in_playfield );
	
		void add_blocks( wstring texture_diffuse );

		XMFLOAT3 get_centre();

		void update( double time_delta );
		void render();

		void move( const Direction in_direction );

		//bool can_move( const string in_direction ) { }
		//bool can_fit

		bool within_playfield( const Direction in_direction );

		//bool block_obstructing(const playfield_blocks * in_blocks, const string in_direction){}

		bool can_rotate( const Rotation in_rotation );

		void rotate( Rotation in_rotation );

	private:

		vector< Quad >			blocks;
		Quad * playfield = nullptr;
		//XMFLOAT3					position{};
		//XMFLOAT3					position_initial{};
		Tetri_centre				centre;
		vector< XMFLOAT2 >			block_offsets;
		double						drop_velocity{};
		//Grid_size					grid_size {};
		enum class					states { next , falling , fast_drop , hard_drop , moving , rotating , sliding , locked , };  // row_made , delete_row_blocks

		std::unique_ptr< int > state() = nullptr;
		//

		//std::map < wstring , DirectX::XMINT2 > translate;
		//rectangle					border{};

		std::map< Direction , XMFLOAT2 >	directions;
		std::map< Rotation , float >		rotations;
};

// 1 block.y = 25 pixels
// 25 pixels / 1 second = 25 pixels/sec

// speed = distance / time
// distance = speed * time

// tetri : public state

// block.update() 
//   block.y += 25 * time (

//Bounding_box get_bounding_box()
//{
//	Bounding_box box;
//	return box;
//}
//
//Bounding_box get_bounding_oriented_box()
//{
//	Bounding_box box = get_bounding_box();
//
//	box.min.x = blocks.front().get_bounding_box().min.x;
//	box.min.y = blocks.front().get_bounding_box().min.y;
//	box.min.z = blocks.front().get_bounding_box().min.z;
//
//	//for( auto & block : blocks )
//	//{
//
//	//	if( block.point.x < box.min.x ) box.min.x = vertex.point.x;
//	//	if( vertex.point.x > box.max.x ) box.max.x = vertex.point.x;
//
//	//	if( vertex.point.y < box.min.y ) box.min.y = vertex.point.y;
//	//	if( vertex.point.y > box.max.y ) box.max.y = vertex.point.y;
//
//	//	if( vertex.point.z < box.min.z ) box.min.z = vertex.point.z;
//	//	if( vertex.point.z > box.max.z ) box.max.z = vertex.point.z;
//	//}
//
//	return box;
//	// for each vertex in apply SRT matrix multiplication
//	// find min and max vertices
//
//	/*	rectangle tetri_border = blocks.front().get_border();
//
//	for( auto & block : blocks )
//	{
//	rectangle block_boarder = block.get_border();
//
//	if( block_boarder.left < tetri_border.left )
//	tetri_border.left = block_boarder.left;
//
//	if( block_boarder.right > tetri_border.right )
//	tetri_border.right = block_boarder.right;
//
//	if( block_boarder.top > tetri_border.top )
//	tetri_border.top = block_boarder.top;
//
//	if( block_boarder.bottom < tetri_border.bottom )
//	tetri_border.bottom = block_boarder.bottom;
//	}
//
//	return tetri_border;*/
//	//rectangle temp_boarder{};
//
//	//return temp_boarder;
//}