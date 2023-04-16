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

UINT8 timer = 0;
BOOLEAN intro_hud_inited = FALSE;

void START() {
	UINT8 collision_tiles[] = { 1, 0 };
	InitScroll(BANK(intro), &intro, collision_tiles, 0);
	PlayMusic(gb_horror, 1);
	stop_music_on_new_state = 0;
	timer = 0;
	intro_hud_inited = FALSE;
}

void UPDATE() {
	if (KEY_PRESSED(J_START)) {
		SetState(StateGame);
		INIT_HUD(memory_picked_hidden);
	}
	if (timer >= 120) {
		if (intro_hud_inited) {
			return;
		}
		INIT_HUD(introHud);
		intro_hud_inited = TRUE;
	}
	else {
		timer++;
	}
}
