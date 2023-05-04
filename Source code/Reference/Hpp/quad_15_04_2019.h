#pragma once

//#include <wrl/client.h> // unique_pointer
s#include "mesh.h"
#include "texture.h"

class Quad : public Mesh
{
	public:

		explicit Quad() {};

		//Quad( const Quad & copy);				
		//Quad & operator = ( const Quad & assign copy );
		//Quad( Quad && move ) // move constructor
		//{
		//	m_diffuse = move( in_quad.m_diffuse );
		//	in_quad.m_diffuse = nullptr;

		//	m_width = in_quad.m_width;
		//	m_height = in_quad.m_height;
		//	m_vertex_colour = in_quad.m_vertex_colour;
		//}

		Quad( const std::wstring in_filename ) 
		{
			load_diffuse( in_filename );
		}
		
		void create_blank( const uint in_width , const uint in_height , const XMUINT4 in_colour )
		//: width( in_width ) , height( in_height ) , vertex_colour( in_vertex_colour )
		//error C2590 : only a constructor can have a base / member initializer list
		{
			//height			= in_height;
			//width			= in_width;
			//colour			= in_colour;

			float �width	= in_width / 2.0f;
			float �height	= in_height / 2.0f;

			vector< vertex_uv > quad_vertices
			{
				//					      position									    texture   u    , v
				vertex_uv( XMFLOAT3( -�width , -�height , 0.0f ) , XMFLOAT2( 0.0f , 1.0f ) ) ,// bottom left
				vertex_uv( XMFLOAT3( -�width ,  �height , 0.0f ) , XMFLOAT2( 0.0f , 0.0f ) ) ,// top left
				vertex_uv( XMFLOAT3(  �width ,  �height , 0.0f ) , XMFLOAT2( 1.0f , 0.0f ) ) ,// top right
				vertex_uv( XMFLOAT3(  �width , -�height , 0.0f ) , XMFLOAT2( 1.0f , 1.0f ) )  // bottom right
			};

			vector< ushort > quad_indices { 0u , 1u , 2u , 0u , 2u , 3u };

			// set_input_layout()
			set_topology( D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST );
			set_vertices( quad_vertices );
			set_indices( quad_indices );

			diffuse.create_blank( in_width , in_height , in_colour );
		}
		
		void load_diffuse( const std::wstring in_filename )
		{
			diffuse.load( in_filename );

			//width	= diffuse.get_width();
			//height	= diffuse.get_height();

			float �width  = diffuse.get_width() / 2.0f;
			float �height = diffuse.get_height() / 2.0f;

			vector< vertex_uv > quad_vertices
			{
				//			   position									  texture u , v
				vertex_uv( XMFLOAT3( -�width , -�height , 0.0f ) , XMFLOAT2( 0.0f , 1.0f ) ) ,// bottom left
				vertex_uv( XMFLOAT3( -�width ,  �height , 0.0f ) , XMFLOAT2( 0.0f , 0.0f ) ) ,// top left
				vertex_uv( XMFLOAT3(  �width ,  �height , 0.0f ) , XMFLOAT2( 1.0f , 0.0f ) ) ,// top right
				vertex_uv( XMFLOAT3(  �width , -�height , 0.0f ) , XMFLOAT2( 1.0f , 1.0f ) )  // bottom right
			};

			vector< ushort > quad_indices { 0u,1u,2u, 0u,2u,3u };

			set_topology( D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST );
			set_vertices( quad_vertices );
			set_indices( quad_indices );
		}

		const float get_width()	 const { return diffuse.get_width(); }
		const float get_height() const { return diffuse.get_height(); }

		const XMFLOAT2 get_size() const 
		{
			return XMFLOAT2( diffuse.get_width() , diffuse.get_height() );
		}

		//void line( const XMFLOAT4 in_points , const Colour in_colour )	{ m_texture->line( in_points , in_colour );	}

		void update( double time_delta ) 
		{
			diffuse.update( time_delta );
			Mesh::update( time_delta );
		}

		void render()
		{
			diffuse.render();
			Mesh::render();
		}

		Texture * get_diffuse() { return & diffuse; }

	private:

		//float width{};
		//float height{};
			
		Texture diffuse;
		//vector<Texture> textures
		//enum class Texture { diffuse , normal , ... }
		
		//DX11::Rectangle border;

				// Mesh mesh;	

		//rectangle get_border() 
		//{
		//	// find min x,y,z & max x,y,z

		//	//min.x = a.x < b.x ? a.x : b.x;  

		//	border.top		= get_position().y + ( height / 2.0f );
		//	border.bottom	= get_position().y - ( height / 2.0f );
		//	border.left		= get_position().x - ( width  / 2.0f );
		//	border.right	= get_position().x + ( width  / 2.0f );

		//	return border;
		//}
};

//normals required ?

		/*
		// copy constructor
		Quad_from_image( const Quad_from_image & in_move_from )
		{
			m_p_image = std::move( in_move_from.m_p_image );
		}

		// move constructor
		Quad_from_image( Quad_from_image && in_move_from )
		{
			m_p_image = std::move( in_move_from.m_p_image );
		}

		// move assignment operator
		Quad_from_image operator = ( Quad_from_image && in_move_from )
		{
			m_p_image = std::move( in_move_from.m_p_image );
		}
		*/
