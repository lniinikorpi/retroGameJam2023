#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Print.h"
IMPORT_MAP(map3);
#include "Music.h"
//DECLARE_MUSIC(Dreamy);



void START() {
	UINT8 collision_tiles[] = { 1, 0 };
	scroll_target = SpriteManagerAdd(SpritePlayer, 296, 16);
	InitScroll(BANK(map3), &map3, collision_tiles, 0);
	//INIT_CONSOLE(font, 3);
	//PlayMusic(Dreamy, 1);
}

void UPDATE() {

	//DPRINT_POS(0, 0);
	//DPrintf("x:%d y:%d s: %d", distance_to_player, enemy_struct.y, is_enemy_spawned);
}
