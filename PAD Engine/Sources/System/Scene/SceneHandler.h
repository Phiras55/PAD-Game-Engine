#pragma once

namespace pad	{
namespace sys	{
namespace sce	{

class SceneHandler final
{
public:
	SceneHandler();
	~SceneHandler();

	SceneHandler(const SceneHandler&)	= delete;
	SceneHandler(SceneHandler&&)		= delete;

private:


public:
	void operator=(const SceneHandler&) = delete;
	void operator=(SceneHandler&&)		= delete;
};

} // namespace sce
} // namespace sys
} // namespace pad