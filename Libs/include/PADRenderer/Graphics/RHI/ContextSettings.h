#pragma once
namespace pad	{
namespace gfx	{
namespace rhi	{

//////////////////////////////
//			Enums			//
//////////////////////////////
enum class E_RENDERER_IMPLEMENTATION_TYPE : uint8
{
	OPENGL
};

enum class E_BUFFER_TYPE : int8
{
	NONE			= 0x00,
	DEPTH_BUFFER	= 0x01,
	STENCIL_BUFFER	= 0x02,
	ALL				= DEPTH_BUFFER | STENCIL_BUFFER
};

enum class E_WINDING_ORDER : bool
{
	COUNTER_CLOCKWISE,
	CLOCKWISE
};

enum class E_CULL_FACE : uint8
{
	BACK,
	FRONT,
	FRONT_AND_BACK
};

enum class E_DEPTH_FUNCTION : uint8
{
	NEVER,
	ALWAYS,
	LESS,
	GREATER,
	EQUAL,
	LEQUAL,
	GEQUAL,
	NOTEQUAL
};

//////////////////////////////
//			Aliases			//
//////////////////////////////
using RendererImplementationType	= E_RENDERER_IMPLEMENTATION_TYPE;
using BufferType					= E_BUFFER_TYPE;
using WindingOrder					= E_WINDING_ORDER;
using DepthFunc						= E_DEPTH_FUNCTION;
using CullFace						= E_CULL_FACE;

//////////////////////////////////
//			Operators			//
//////////////////////////////////
E_BUFFER_TYPE  operator| (const E_BUFFER_TYPE& left, const E_BUFFER_TYPE& right);
E_BUFFER_TYPE& operator|=(E_BUFFER_TYPE& left, const E_BUFFER_TYPE& right);
E_BUFFER_TYPE  operator& (const E_BUFFER_TYPE& left, const E_BUFFER_TYPE& right);
E_BUFFER_TYPE& operator&=(E_BUFFER_TYPE& left, const E_BUFFER_TYPE& right);

//////////////////////////////
//			Structs			//
//////////////////////////////
struct ContextSettings final
{
	ContextSettings() :
		viewportSize		(0, 0),
		clearColor			(0.f, 0.f, 0.f, 1.f),
		frameBufferCount	(0),
		stencilMask			(0x00),
		enabledBuffers		(E_BUFFER_TYPE::ALL),
		depthFunc			(E_DEPTH_FUNCTION::LESS),
		windingOrder		(E_WINDING_ORDER::COUNTER_CLOCKWISE),
		cullFace			(E_CULL_FACE::BACK),
		implementationType	(E_RENDERER_IMPLEMENTATION_TYPE::OPENGL)
	{

	}

	math::Vec2i					viewportSize;
	math::Vec4f					clearColor;
	uint16						frameBufferCount;
	uint32						stencilMask;
	BufferType					enabledBuffers;
	DepthFunc					depthFunc;
	WindingOrder				windingOrder;
	CullFace					cullFace;
	RendererImplementationType	implementationType;
};

} // namespace rhi
} // namesapce gfx
} // namesapce pad