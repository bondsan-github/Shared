#include <Header.hlsli>
 
interpolants main( in vertex input )
{
    interpolants output = (interpolants) 0;
    
    output.position = mul( input.position, model );
    output.position = mul( output.position, view );
    output.position = mul( output.position, projection );
    
    //output.position   = input.position;
    output.texture_uv = input.texture_uv;
	
    return output;
}

