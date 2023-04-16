#include "Banks/SetAutoBank.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

UINT8 anim[] = {4, 0,1,2,3};
void START() {
	SetSpriteAnim(THIS, anim, 15);
}

void UPDATE() {

	THIS->x++;
}

void DESTROY() {
}