// Include Vircon libraries
#include "audio.h"
#include "input.h"
#include "math.h"
#include "memcard.h"
#include "misc.h"
#include "string.h"
#include "time.h"
#include "video.h"

// -----------------------------------------------
// Texture definitions
// -----------------------------------------------
enum TxRegion
{
	TEXTURE_REGION_HERO_RIGHT,
	TEXTURE_REGION_HERO_UP,
	TEXTURE_REGION_HERO_LEFT,
	TEXTURE_REGION_HERO_DOWN,

	TX_REGION_ENEMY_BIG,
	TX_REGION_ENEMY_SMALL,
	TX_REGION_EXPLOSION,
	TX_REGION_HERO,
	TX_REGION_LASER,
	TX_REGION_MINE,
	TX_REGION_OPTION,
	TX_REGION_WHITE_1X1,
	TX_REGION_WHITE_2X2,
	
	TxRegion_IGNORE
};

// -----------------------------------------------
// Sound definitions
// -----------------------------------------------
#define BGM_LAW 0

#define BGM_CHANNEL 15 // Reserve the last sound channel for music
#define BGM_DEFAULT 0 // The default BGM to play
#define BGM_VOLUME 0.3


// -----------------------------------------------
// Gameplay definitions
// -----------------------------------------------
#define NUMBER_OF_GAMEPADS 4
#define TILE_SIZE 16
#define HERO_SPEED 2
#define HERO_LASER_SPEED 4
#define SPAWNER_INTERVAL 30
#define SPAWNER_INTERVAL_RANGE 30
