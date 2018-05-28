#pragma once

#include <Utilities/Export.h>
#include <System/ECS/MeshRenderer.h>
#include <Graphics/Model/Skeleton.h>
#include <Core/Timer.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API AnimRenderer : public MeshRenderer
{
public:
	AnimRenderer();
	AnimRenderer(	const AnimRenderer& _other);
	AnimRenderer(	const std::string&	_meshName, 
					const std::string&	_materialName, 
					const std::string&	_skeletonName,
					const std::string&	_animName);
	~AnimRenderer();

private:
	std::string		m_skeletonName;
	std::string		m_currentAnim;
	int				m_currentKey;
	float			m_keyFrameDuration;
	core::Timer		m_animTimer;
	float			m_animSpeed;
	bool			m_loop;

private:
	static alias::ComponentID	m_AR_id;
	const std::string			m_name = "AnimRenderer";

public:
	void Init()							override;
	void Start()						override;
	void Update()						override;
	void FixedUpdate()					override;
	void LateUpdate()					override;

	json Serialize()					override;
	void Deserialize(const json& j)		override;

	inline const std::string& GetName() override { return m_name; }

public:
	inline const alias::ComponentID GetType() const override { return m_AR_id; }

	inline const	std::string&	GetSkeletonName()	const	{ return m_skeletonName; }
	inline const	std::string&	GetAnimName()		const	{ return m_currentAnim; }
	inline const	core::Timer&	GetTimer()			const	{ return m_animTimer; }
	inline			core::Timer&	GetTimer() 					{ return m_animTimer; }
	inline const	int				GetCurrentFrame()	const	{ return m_currentKey; }
	inline const	float			GetFrameDuration()	const	{ return m_keyFrameDuration; }
	inline const	bool			GetLoop()			const	{ return m_loop; }
	inline const	float			GetAnimSpeed()		const	{ return m_animSpeed; }

	inline void SetCurrentFrame(const int _key)					{ m_currentKey = _key; }
	inline void SetFrameDuration(const float _duration)			{ m_keyFrameDuration = _duration; }
	inline void SetAnimSpeed(const float _animSpeed)			{ m_animSpeed = _animSpeed; }
	inline void SetLoop(const bool _loop)						{ m_loop = _loop; }

	inline void	SetAnim(const std::string _name);


public:
	void operator=(const AnimRenderer& _other);
};

} // namespace ecs
} // namespace sys
} // namespace pad