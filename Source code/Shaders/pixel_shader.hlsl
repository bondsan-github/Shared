#include <Header.hlsli>
 
float4 main( interpolants input ) : SV_TARGET
//pixel main( in interpolants input )
{
    //pixel output;
    float4 output;
    
    //output.colour = diffuse.Sample( sampler_0, input.texture_uv );
    output = diffuse.Sample( sampler_0, input.texture_uv );
    //output = float4(1, 1, 1, 1);
    
    //output.position   = input.position;
    //output.texture_uv = input.texture_uv;
    
    return output;
}
/*
 Pixel shader must always have float4 pos : SV_POSITION 
 semantics for input position of pixel( It is a one of the System Value semantics ).

 The output value that will be stored in a render target.
 The index indicates which of the 8 possibly bound render targets to write to.
 The value is available to all shaders. 
*/
