cbuffer CBufferPerObject 
{
	float4x4 WorldViewProjection;
};


struct VS_INPUT
{
	float4 ObjectPosition : POSITION;
	float4 Color : COLOR;
};

struct VS_OUTPUT
{
	float4 Position : SV_POSITION;
	float4 Color : COLOR;
};

VS_OUTPUT main(VS_INPUT IN)
{
	VS_OUTPUT OUT = (VS_OUTPUT)0;
	
	OUT.Position = mul(IN.ObjectPosition, WorldViewProjection);

	OUT.Color = IN.Color;

	return OUT;
}