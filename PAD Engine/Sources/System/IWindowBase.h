#pragma once
#include <System/Win_Info.h>

namespace pad
{
namespace sys
{

class IWindowBase
{
protected:
	bool m_isOpen;

public:
	virtual void PollEvents() = 0;
	virtual void Resize(const int w, const int h) = 0;
	virtual void ReloadInformations(const Win_Info& infos) = 0;
	virtual void Init(const Win_Info& infos) = 0;
	virtual bool IsOpen() = 0;

public:
	// TODO : Getters and Setters for Size/Position...
};

} // namespace sys
} // namespace pad