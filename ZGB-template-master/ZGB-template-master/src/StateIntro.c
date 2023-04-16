#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Print.h"
#include "Keys.h"
#include "Music.h"
IMPORT_MAP(intro);
IMPORT_MAP(introHud);
IMPORT_MAP(memory_picked_hidden);
DECLARE_MUSIC(gb_horror);

UINT8 timer_cookie = 0;

void START() {
	UINT8 collision_tiles[] = { 1, 0 };
	InitScroll(BANK(intro), &intro, collision_tiles, 0);
	PlayMusic(gb_horror, 1);
	stop_music_on_new_state = 0;
	timer_cookie = 0;
}

void UPDATE() {
	if (KEY_PRESSED(J_START)) {
		SetState(StateGame);
		INIT_HUD(memory_picked_hidden);
	}
	timer_cookie++;
	if (timer_cookie == 120) {
		INIT_HUD(introHud);
	}
}
