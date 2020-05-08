#include "powerups.h"

#include "tilemap.h"
#include "mates.h"
#include "assets.h"
#include "window.h"

extern float mainClock;


void GunUp::Draw() const
{
	float y = 3.f * sin(mainClock);

	Window::Draw(Assets::marioTexture, pos.x, pos.y - y)
		.withOrigin(8, 8)
		.withRect(5 * 16, 11 * 16, 16, 16);

}



void HealthUp::Draw() const
{
	if (TileMap::instance()->getTile(TileMap::toTiles(pos)).isBreakable()) {
		//Don't draw behind breakables
		return;
	}

	float y = 3.f * sin(mainClock);

	Window::Draw(Assets::marioTexture, pos.x, pos.y - y)
		.withOrigin(8, 8)
		.withRect(6 * 16, 11 * 16, 16, 16);
}

