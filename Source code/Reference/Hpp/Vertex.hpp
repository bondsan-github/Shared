#pragma once

#include <DirectXMath.h>

#include "Colour.hpp"

using DirectX::XMFLOAT2;
using DirectX::XMFLOAT3;

//enum class vertex_types { vertex , vertex_colour , vertex_texture };

struct vertex
{
	vertex( XMFLOAT3 const & position = XMFLOAT3( 0.0f , 0.0f , 0.0f ) )
    : position( position )
    {
    }

	bool operator == ( vertex const & vertex )
	{
		if(    position.x != vertex.position.x 
            || position.y != vertex.position.y 
            || position.z != vertex.position.z ) return false;
		else 
            return true;
	}
	
	//operator = ( vertex )
	//operator - ( vertex ) 

	private:

		XMFLOAT3 position;
};


struct vertex_colour : public vertex
{
	vertex_colour( XMFLOAT3 const &  position,
                   Colour colour = Colour() )
        : vertex( position ) , colour( colour )
    {
    }

	private:

		Colour colour;
};

// class float2
// class float3

struct vertex_colour_texture : public vertex_colour
{
	/*vertex_colour_texture(XMFLOAT3 & const position ,
                           Colour & const colour ,
                           XMFLOAT2 texture_uv )*/
        vertex_colour_texture( XMFLOAT3 const & position ,
                               Colour const & colour ,
                               XMFLOAT2 const & texture_uv )
	: vertex_colour( position, colour ) , texture_uv( texture_uv )
    {
    }

	private:

		XMFLOAT2 texture_uv;
};

