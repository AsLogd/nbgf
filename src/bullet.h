#pragma once

#include "entity.h"
#include "partsys.h"
#include "selfregister.h"

struct Bullet : CircleEntity, SelfRegister<Bullet>
{
	static inline const float kColliderRadius = 7.5f;
	static inline const float kSpriteScale = 1.5f;

	static inline PartSys particles = PartSys(nullptr);
	static void InitParticles();

	Bullet(vec position, vec velocity)
		: CircleEntity(position, kColliderRadius, velocity)
	{
	}

	void Explode();

	void Update(float dt);
	void Draw() const;

};
