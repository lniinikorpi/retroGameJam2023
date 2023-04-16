#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

const UINT8 anim_closed[] = { 1, 0,};
const UINT8 anim_open[] = { 1, 1, };
typedef struct {
	BOOLEAN is_open;
} CUSTOM_DATA;
CUSTOM_DATA* data;

void START() {
	data = (CUSTOM_DATA*)THIS->custom_data;
	UINT8 i;
	Sprite* spr;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type != SpritePlayer) {
			continue;
		}
		if (spr->custom_data[1]) {
			SetSpriteAnim(THIS, anim_open, 15);
			data->is_open = TRUE;
		}
		else {
			SetSpriteAnim(THIS, anim_closed, 15);
			data->is_open = FALSE;
		}
	}
}

void UPDATE() {
	if (data->is_open == FALSE) {
		return;
	}
	SetSpriteAnim(THIS, anim_open, 15);
	UINT8 i;
	Sprite* spr;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type != SpritePlayer) {
			continue;
		}

		if (!CheckCollision(THIS, spr)) {
			continue;
		}
		spr->custom_data[1] = FALSE;
		current_state++;
		SetState(current_state);
	}
}

void DESTROY() {
}