#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Print.h"

#include "Music.h"
DECLARE_MUSIC(Unknown_Caverns);
IMPORT_TILES(font);
IMPORT_MAP(map5);


void START() {
	UINT8 collision_tiles[] = { 1, 254, 0 };
	scroll_target = SpriteManagerAdd(SpritePlayer, 120, 16);
	InitScroll(BANK(map5), &map5, collision_tiles, 0);
	//INIT_CONSOLE(font, 3);
	//
	PlayMusic(Unknown_Caverns, 1);
}

void UPDATE() {
	
	//DPRINT_POS(0, 0);
	//DPrintf("x:%d y:%d s: %d", distance_to_player, enemy_struct.y, is_enemy_spawned);
}
