#pragma once
#include <iostream>

#include <Graphics/RenderSettings.h>
#include <System/IModule.h>

namespace pad
{
namespace gfx
{

class Renderer final : public sys::IModule
{
public:
	Renderer();
	virtual ~Renderer() = default;

	Renderer(const Renderer&)	= delete;
	Renderer(Renderer&&)		= delete;

public:
	virtual void StartModule();
	virtual void StopModule();

	void Init(const RenderSettings& settings);
	void ClearBuffer();
	void Draw();

private:
	void InitContext(const math::Vec4f& _clearColor);
	void InitViewPort(const math::Vec2i& _viewportSize);

public:
	void operator=(const Renderer&) = delete;
	void operator=(Renderer&&)		= delete;
};

} // namespace gfx
} // namespace pad