#pragma once
namespace pad	{
namespace sys	{
namespace ecs	{

class AComponent
{
public:
	virtual ~AComponent() = default;

public:
	virtual void Start()		= 0;
	virtual void Init()			= 0;
	virtual void Update()		= 0;
	virtual void FixedUpdate()	= 0;
	virtual void LateUpdate()	= 0;
};

} // namespace ecs
} // namespace sys
} // namespace pad