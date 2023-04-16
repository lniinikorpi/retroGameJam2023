#include "Banks/SetAutoBank.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

UINT8 anim_not_picked[] = {1, 0};
UINT8 anim_picked[] = { 1, 1 };
void START() {
	UINT8 i;
	Sprite* spr;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type != SpritePlayer) {
			continue;
		}
		if (spr->custom_data[1]) {
			SpriteManagerRemoveSprite(THIS);
		}
	}
	SetSpriteAnim(THIS, anim_not_picked, 15);
}

void UPDATE() {
	UINT8 i;
	Sprite* spr;
	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type != SpritePlayer) {
			continue;
		}

		if (!CheckCollision(THIS, spr)) {
			continue;
		}
		UINT8 y;
		Sprite* spr2;
		SPRITEMANAGER_ITERATE(y, spr2) {
			if (spr2->type != SpriteDoor) {
				continue;
			}
			spr2->custom_data[0] = TRUE;
			break;
		}
		spr->custom_data[0] = TRUE;
		spr->custom_data[1] = TRUE;
		SpriteManagerRemoveSprite(THIS);
		break;
	}

}

void DESTROY() {
}