#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Print.h"

typedef struct {
	INT16 x;
	INT16 y;
} ENEMY;

typedef struct {
	BOOLEAN is_moving;
} CUSTOM_DATA;

ENEMY enemy_struct = { 100, 50 };

BOOLEAN is_enemy_spawned = FALSE;

INT16 patrol_targets_x[4] = {0};
INT16 patrol_targets_y[4] = {0};
UINT8 patrol_target_index = 0;
BOOLEAN is_chasing = FALSE;
INT8 enemy_speed = 1;
Sprite* enemy_sprite;
Sprite* player_sprite;
CUSTOM_DATA* e_data;

void START() {
	//INIT_CONSOLE(font, 3);
	e_data = (CUSTOM_DATA*)THIS->custom_data;
	e_data->is_moving = TRUE;
	enemy_struct.x = 75;
	enemy_struct.y = 10;
	UINT8 i;
	Sprite* spr;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type != SpritePlayer) {
			continue;
		}
		player_sprite = spr;
	}
	patrol_target_index = 0;
	patrol_targets_x[0] = 75;
	patrol_targets_y[0] = 10;

	patrol_targets_x[1] = 250;
	patrol_targets_y[1] = 10;

	patrol_targets_x[2] = 250;
	patrol_targets_y[2] = 100;

	patrol_targets_x[3] = 75;
	patrol_targets_y[3] = 100;
}

void UPDATE() {
	if (!e_data->is_moving) {
		if (is_enemy_spawned) {
			SpriteManagerRemoveSprite(enemy_sprite);
			is_enemy_spawned = FALSE;
		}
		return;
	}
	INT16 movX = 0;
	INT16 movY = 0;
	//Chase player
	if (is_chasing) {
		movX = player_sprite->x - enemy_struct.x;
		movY = player_sprite->y - enemy_struct.y;
	}
	//Patrol through the targets
	else {
		//In current target
		if (enemy_struct.x == patrol_targets_x[patrol_target_index] && enemy_struct.y == patrol_targets_y[patrol_target_index]) {
			UINT8 arrayLength = sizeof(patrol_targets_x) / sizeof(patrol_targets_x[0]);
			if (patrol_target_index + 1 < arrayLength) {
				patrol_target_index++;
			}
			else {
				patrol_target_index = 0;
			}
		}
		movX = patrol_targets_x[patrol_target_index] - enemy_struct.x;
		movY = patrol_targets_y[patrol_target_index] - enemy_struct.y;
	}
	//DPRINT_POS(0, 0);
	//DPrintf("x:%d y:%d s: %d", patrol_targets_x[patrol_target_index], patrol_targets_y[patrol_target_index], is_enemy_spawned);

	if (movX > 0) {
		movX = enemy_speed;
	}
	else if (movX < 0) {
		movX = -enemy_speed;
	}

	if (movY > 0) {
		movY = enemy_speed;
	}
	else if (movY < 0) {
		movY = -enemy_speed;
	}

	enemy_struct.x += movX;
	enemy_struct.y += movY;


	INT16 distanceX = player_sprite->x - enemy_struct.x;
	INT16 distanceY = player_sprite->y - enemy_struct.y;
	if (distanceX > 120 || distanceX < -120) {
		distanceX = 120;
	}
	if (distanceY > 120 || distanceY < -120) {
		distanceY = 120;
	}
	INT16 distance_to_player = distanceX * distanceX + distanceY * distanceY;
	if (!is_enemy_spawned && distance_to_player < 140 * 140) {
		enemy_sprite = SpriteManagerAdd(SpriteEnemy, enemy_struct.x, enemy_struct.y);
		is_enemy_spawned = TRUE;
	}

	if (is_enemy_spawned) {
		//TranslateSprite(enemy_sprite, movX, movY);
		enemy_sprite->x = enemy_struct.x;
		enemy_sprite->y = enemy_struct.y;
		enemy_sprite->custom_data[0] = movX;
	}

	if (distance_to_player < 50 * 50) {
		is_chasing = TRUE;
	}
	else {
		is_chasing = FALSE;
	}
}

void DESTROY() {

}