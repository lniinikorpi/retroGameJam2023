#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Print.h"
#include "Keys.h"
IMPORT_TILES(font);
IMPORT_MAP(dead);

void START() {
	UINT8 collision_tiles[] = { 1, 0 };
	InitScroll(BANK(dead), &dead, collision_tiles, 0);
}

void UPDATE() {
	if (KEY_PRESSED(J_START)) {
		SetState(StateIntro);
	}
}
