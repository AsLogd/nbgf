#include "flyingalien.h"

#include "jumpman.h"
#include "collide.h"
#include "window.h"
#include "assets.h"
#include "shader.h"
#include "rand.h"
#include "tiled_objects_areas.h"
#include "common_tilemapcharacter.h"
#include "common_enemy.h"

constexpr const float speedInitial = 25;
constexpr const float speedAlert = 75;
constexpr const float speedAttack = 100;

constexpr const float overshotEndCharge = 10;
constexpr const float overshotReturnSpeed = 50;

constexpr const float flyingAlienHealth = 4;

constexpr const float hitTime = 0.5f;
constexpr const float prepareAttackTime = 0.5f;
constexpr const float exitAttackTime = 0.2f;

constexpr const float spriteScale = .75f;
constexpr const float spriteRadius = 15.f;

// Area that if intersects with the player will trigger an attack
constexpr const vec playerNearbyArea = vec(100, 100);

FlyingAlien::FlyingAlien(vec pos)
	: CircleEntity(pos - vec(0,8), spriteRadius)
	, anim(AnimLib::FLYING_ALIEN)
{
	screen = ScreenManager::instance()->FindScreenContaining(pos);
	initialPos = this->pos;
	initialVelX = Rand::OnceEvery(2) ? -speedInitial : speedInitial;
	Reset();

	int bounds_index = FindIndexOfSmallestBoundsContaining(pos, Tiled::Areas::alien_bounds);
	if (bounds_index > -1) {
		bounds = Tiled::Areas::alien_bounds[bounds_index];
	} else if (screen > -1) {
		bounds = ScreenManager::instance()->ScreenBounds(screen);
	} else {
		Debug::out << "Unbounded FlyingAlien";
	}
}

void FlyingAlien::Reset() {
	pos = initialPos;
	health = flyingAlienHealth;
	vel.x = initialVelX;
	state = State::FLYING;
}

BoxBounds FlyingAlien::ChargeBounds() const
{
	BoxBounds chargeBounds = BoxBounds(pos, playerNearbyArea);
	if (vel.x < 0) {
		chargeBounds.left -= chargeBounds.width;
		chargeBounds.left += spriteRadius;
	}
	else {
		chargeBounds.left -= spriteRadius;
	}
	return chargeBounds;
}

void FlyingAlien::Update(float dt)
{
	if (!InSameScreenAsPlayer(screen)) {
		if (pos != initialPos) {
			Reset();
		}
		return;
	}

	hitTimer -= dt;
	const vec* damageFromPlayerPos = ReceiveDamageFromPlayer(Bounds(), hitTimer > 0.f);
	if (damageFromPlayerPos) {
		TakeDamage(*damageFromPlayerPos);
		if (alive == false) return;
	}

	anim.Update(dt);

	JumpMan* player = JumpMan::instance();

	float walkDir = vel.x > 0 ? 1 : -1;

	switch (state)
	{
	case State::CHARGING:
	{
		pos.x += vel.x * dt;
		pos.y = initialPos.y + walkDir*std::sin(((pos.x - beginAttackX) / playerNearbyArea.x) * M_PI) * playerNearbyArea.y;
		if (walkDir*(pos.x - beginAttackX) > playerNearbyArea.x) {
			timer = 0.f;
			state = State::EXIT_CHARGE;
		}
	}
	break;
	case State::EXIT_CHARGE:
	{
		timer += dt;
		pos.x += Mates::Lerp(speedAttack, speedAlert, (timer / exitAttackTime)) * walkDir * dt;
		pos.y = initialPos.y - std::sin((timer/exitAttackTime) * M_PI/2) * overshotEndCharge;
		if (timer >= exitAttackTime) {
			state = State::FLYING;
			if (pos.x < player->pos.x) {
				vel.x = speedAlert;
			} 
			else {
				vel.x = -speedAlert;
			}
		}
	}
	break;
	case State::ENTER_CHARGE:
	{
		timer += dt;
		if (timer > prepareAttackTime) {
			state = State::CHARGING;
			beginAttackX = pos.x;
			timer = 0.f;
		}
	}
	break;
	case State::FLYING: 
	{

		BoxBounds chargeBounds = ChargeBounds();

		if (IsGoingToHitAWall(chargeBounds.Center(), chargeBounds.Size(), vel, dt)
			|| IsGoingToLeaveBounds(chargeBounds.Center(), chargeBounds.Size(), vel, dt, bounds)
		) {
			vel.x = -vel.x;
		}
		pos.x += vel.x * dt;

		if (Mates::IsNearlyEqual(pos.y, initialPos.y, 0.5f)) {
			if (Collide(player->Bounds(), ChargeBounds())) {
				state = State::ENTER_CHARGE;
				timer = 0.f;

				if (pos.x < player->pos.x) {
					vel.x = speedAttack;
				}
				else {
					vel.x = -speedAttack;
				}

				float bigDtAttack = playerNearbyArea.y / speedAttack; // total time that will be spent attacking
				if (IsGoingToHitAWall(chargeBounds.Center(), chargeBounds.Size(), vel, bigDtAttack)
					|| IsGoingToLeaveTheScreen(chargeBounds.Center(), chargeBounds.Size(), vel, bigDtAttack, screen))
				{
					//Debug::out << "Flipping because would hit a wall during the attack";
					vel.x = -vel.x;
				}
			}
		} else if (pos.y > initialPos.y) {
			pos.y -= overshotReturnSpeed*dt;
		} else if (pos.y < initialPos.y) {
			pos.y += overshotReturnSpeed*dt;
		}
	}
	break;
	}

	if (!damageFromPlayerPos) {
		DamagePlayerOnCollision(Bounds());
	}
}

void FlyingAlien::TakeDamage(vec src) {
	hitTimer = hitTime;
	
	// TODO: Knockback
	
	if (state == State::FLYING) {
		if (pos.x < JumpMan::instance()->pos.x) {
			vel.x = speedAttack;
		}
		else {
			vel.x = -speedAttack;
		}
	}

	health--;
	if (health <= 0) {
		DieWithSmallExplosion(this);
	}
}

void FlyingAlien::Draw() const
{
	if (hitTimer > 0.f) {
		Assets::tintShader.Activate();
		Assets::tintShader.SetUniform("flashColor", 1.f, 0.f, 0.f, 0.7f);
	}

	vec drawPos = pos + vec(vel.x > 0? 2 : -2,(std::sin((initialPos.x + pos.x)*0.1f)*4) - 3);
	if (state == State::ENTER_CHARGE) {
		drawPos.y -= sinf((timer / prepareAttackTime) * M_PI) * Tile::Size;
	}

	GPU_Rect rect = anim.CurrentFrameRect();
	Window::Draw(Assets::scifiTexture, drawPos)
		.withRect(rect)
		.withScale(vel.x> 0? -spriteScale : spriteScale, spriteScale)
		.withOrigin(rect.w / 2, rect.h / 2);

	Shader::Deactivate();

	// Debug-only
	pos.DebugDraw();
	vec(pos.x, initialPos.y).DebugDraw(0, 0, 255);
	Bounds().DebugDraw();
	ChargeBounds().DebugDraw(255, 0, 255);
}
