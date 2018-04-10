#pragma once

#include <System/Resource/AResourceManager.h>
#include <Graphics/Model/Mesh.h>

namespace pad	{
namespace sys	{
namespace res	{

class MeshManager //: public AResourceManager
{
public:
	MeshManager();
	~MeshManager();

public:
	//gfx::mod::Mesh* const GetResource(const std::string _name) override;
};

} // namespace res
} // namespace sys
} // namespace pad