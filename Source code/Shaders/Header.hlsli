struct vertex 
{
    float4 position : SV_POSITION;
    float2 texture_uv : TEXCOORD;
};

cbuffer buffer_model      : register( b0 ) { matrix model; };
cbuffer buffer_view       : register( b1 ) { matrix view; };
cbuffer buffer_projection : register( b2 ) { matrix projection; };

struct interpolants // Pixel shader input
{
    float4 position : SV_POSITION;
    float2 texture_uv : TEXCOORD;
};

struct pixel
{
    float4 colour : SV_Target;
};

Texture2D diffuse : register( t0 );
SamplerState sampler_0 : register( s0 );

// const vs_buffer_model = 0;
// vs_buffer_view = 1;
// vs_buffer_projection = 2;
