#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateIntro)\
_STATE(StateGame)\
_STATE(StateGame1)\
_STATE(StateGame2)\
_STATE(StateGame3)\
_STATE(StateGame4)\
_STATE(StateEnd)\
_STATE(StateDead)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteDoor, spriteDoor)\
_SPRITE_DMG(SpriteKey, spriteKey)\
_SPRITE_DMG(SpriteEnemy, robber)\
_SPRITE_DMG(SpriteEnemyLogic, enemyLogic)\
_SPRITE_DMG(SpriteCookie, cookieanimation)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif