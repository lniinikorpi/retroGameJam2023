#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Scroll.h"
IMPORT_MAP(memory_picked);
IMPORT_MAP(memory_picked_hidden);
IMPORT_MAP(ghost_vanished);
IMPORT_MAP(memory0);
IMPORT_MAP(memory1);
IMPORT_MAP(memory2);
IMPORT_MAP(memory3);
IMPORT_MAP(memory4);

const UINT8 anim_idle_right[] = { 2 , 0, 1 };
const UINT8 anim_idle_left[] = { 2 , 2, 3 };
//const UINT8 anim_walk[] = { 2, 1, 2 };
const UINT8 movement_speed = 2;
Sprite* enemy_logic;
UINT8 hud_index = 0;
BOOLEAN a_pressed = FALSE;

typedef struct {
	BOOLEAN is_show_hud;
	BOOLEAN has_key;
} CUSTOM_DATA;

BOOLEAN in_hud = FALSE;

CUSTOM_DATA* p_data;

void START() {
	enemy_logic = SpriteManagerAdd(SpriteEnemyLogic, THIS->x, THIS->y);
	p_data = (CUSTOM_DATA*)THIS->custom_data;
	p_data->is_show_hud = FALSE;
	p_data->has_key = FALSE;
	hud_index = 0;
	BOOLEAN a_pressed = FALSE;
	SetSpriteAnim(THIS, anim_idle_right, 5);
}

void UPDATE() {
	ManageInputs();
	enemy_logic->x = THIS->x;
	enemy_logic->y = THIS->y;

	UINT8 i;
	Sprite* spr;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type != SpriteEnemy) {
			continue;
		}

		if (!CheckCollision(THIS, spr)) {
			continue;
		}
		SetState(StateDead);
	}
	if (p_data->is_show_hud) {
		INIT_HUD(memory_picked);
		in_hud = TRUE;
		p_data->is_show_hud = FALSE;
		//SetSpriteAnim(THIS, anim_idle, 15);
		enemy_logic->custom_data[0] = FALSE;
	}

	if (in_hud && KEY_PRESSED(J_A) && !a_pressed) {
		a_pressed = TRUE;
		if (hud_index < 2) {
			hud_index++;
			switch (hud_index)
			{
			case 1:
				switch (current_state)
				{
				case StateGame:
					INIT_HUD(memory0);
					break;
				case StateGame1:
					INIT_HUD(memory1);
					break;
				case StateGame2:
					INIT_HUD(memory2);
					break;
				case StateGame3:
					INIT_HUD(memory3);
					break;
				case StateGame4:
					INIT_HUD(memory4);
					break;
				}
				break;

			default:
				break;
			case 2:
				INIT_HUD(ghost_vanished);
				break;
			}
			return;
		}
		INIT_HUD(memory_picked_hidden);
		in_hud = FALSE;
	}
	if (KEY_RELEASED(J_A)) {
		a_pressed = FALSE;
	}
}

void ManageInputs() {
	if (in_hud) {
		return;
	}
	if (KEY_PRESSED(J_UP)) {
		TranslateSprite(THIS, 0, -movement_speed);
		//SetSpriteAnim(THIS, anim_walk, 15);
	}
	if (KEY_PRESSED(J_DOWN)) {
		TranslateSprite(THIS, 0, movement_speed);
		//SetSpriteAnim(THIS, anim_walk, 15);
	}
	if (KEY_PRESSED(J_LEFT)) {
		TranslateSprite(THIS, -movement_speed, 0);
		SetSpriteAnim(THIS, anim_idle_left, 5);
		//SetSpriteAnim(THIS, anim_walk, 15);
	}
	if (KEY_PRESSED(J_RIGHT)) {
		TranslateSprite(THIS, movement_speed, 0);
		SetSpriteAnim(THIS, anim_idle_right, 5);
	}
	if (keys == 0) {
		//SetSpriteAnim(THIS, anim_idle, 15);
	}
}

void DESTROY() {
}