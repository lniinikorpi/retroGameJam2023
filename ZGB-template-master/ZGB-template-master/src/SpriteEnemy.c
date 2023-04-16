#include "Banks/SetAutoBank.h"

#include "SpriteManager.h"
#include "ZGBMain.h"

const UINT8 anim_e_idle_right[] = { 2 , 0, 1 };
const UINT8 anim_e_idle_left[] = { 2 , 2, 3 };

extern BOOLEAN is_enemy_spawned;

typedef struct {
	INT8 direction;
} CUSTOM_DATA;

CUSTOM_DATA* enemy_sprite_data;

void START() {
	enemy_sprite_data = (CUSTOM_DATA*)THIS->custom_data;
	SetSpriteAnim(THIS, anim_e_idle_right, 5);
}

void UPDATE() {
	switch (enemy_sprite_data->direction)
	{
	case 1:
		SetSpriteAnim(THIS, anim_e_idle_right, 5);
		break;
	case -1:
		SetSpriteAnim(THIS, anim_e_idle_left, 5);
		break;
	}
}

void DESTROY() {
	is_enemy_spawned = FALSE;
}