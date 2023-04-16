#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Print.h"
#include "Keys.h"
IMPORT_TILES(font);
IMPORT_MAP(credit);

UINT16 timer;
BOOLEAN spawned;

void START() {
	UINT8 collision_tiles[] = { 1, 0 };
	InitScroll(BANK(credit), &credit, collision_tiles, 0);
	spawned = FALSE;
	timer = 0;
}

void UPDATE() {
	if (KEY_PRESSED(J_START)) {
		SetState(StateIntro);
	}
	timer++;
	if (timer > 600 && !spawned) {
		spawned = TRUE;
		SpriteManagerAdd(SpriteCookie, -20, 100);
	}
}
