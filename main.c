#include "main.h"
#include "ecs.h"
#include "ecs_utility.h"
#include "pickups.h"
#include "utility.h"
#include "hero.h"
#include "systems.h"
#include "mobs.h"
#include "stars.h"

// -----------------------------------------------
// Global variables
// -----------------------------------------------
bool ContinueLoop;
int SpawnerTimer;

// -----------------------------------------------
// Functions
// -----------------------------------------------
void init(void)
{
// -----------------------------------------------
// Set up textures
// -----------------------------------------------
	select_texture(0);
	define_region_matrix(TEXTURE_REGION_HERO_RIGHT, 0, 0, 15, 15, 0, 0, 4, 1, 0);

	select_region(TX_REGION_HERO);
	define_region_topleft(TILE_SIZE*0, TILE_SIZE*2, TILE_SIZE*2, TILE_SIZE*4);

	select_region(TX_REGION_WHITE_1X1);
	define_region_topleft(0, 22, 0, 22);

	select_region(TX_REGION_WHITE_2X2);
	define_region_topleft(0, 22, 1, 23);

	select_region(TX_REGION_MINE);
	define_region_topleft(TILE_SIZE*5, TILE_SIZE*0, TILE_SIZE*6, TILE_SIZE*1);

	select_region(TX_REGION_ENEMY_SMALL);
	define_region_topleft(TILE_SIZE*10, TILE_SIZE*0, TILE_SIZE*11, TILE_SIZE*1);

	select_region(TX_REGION_ENEMY_BIG);
	define_region_topleft(TILE_SIZE*0, TILE_SIZE*4, TILE_SIZE*4, TILE_SIZE*8);

	select_region(TX_REGION_OPTION);
	define_region_topleft(TILE_SIZE*9, TILE_SIZE*0, TILE_SIZE*10, TILE_SIZE*1);

	select_region(TX_REGION_LASER);
	define_region_topleft(TILE_SIZE*8, TILE_SIZE*0, TILE_SIZE*9, TILE_SIZE*1);

	select_region(TX_REGION_EXPLOSION);
	define_region_topleft(TILE_SIZE*1, TILE_SIZE*1, TILE_SIZE*2, TILE_SIZE*2);
// -----------------------------------------------
// Set up audio
// -----------------------------------------------
	// Configure each BGM to loop
	select_sound(BGM_LAW);
	set_sound_loop(true);
	
	// Lower the volume on all sound channels
	for (int i = 0; i < sound_channels; i++)
	{
		select_channel(i);
		set_channel_volume(BGM_VOLUME);
	}

	// Begin playing music
	play_sound_in_channel(BGM_DEFAULT, BGM_CHANNEL);
	
// -----------------------------------------------
// Misc. setup
// -----------------------------------------------
	// Set the random seed
	srand(get_time());

	// Select the first connected gamepad
	for (int i = 0; i < NUMBER_OF_GAMEPADS; i++)
	{
		select_gamepad(i);
		if (gamepad_is_connected()) break;
	}

// -----------------------------------------------
// Game setup
// -----------------------------------------------
	ContinueLoop = true;

	SpawnerTimer = 0;

	InitStarfield();
	CreateHero(screen_width/2 - TILE_SIZE, screen_height - TILE_SIZE*3);
}

void update(void)
{
	UpdateStarfield();

	run_system(SYS_TOP_DOWN_MOVE);
	run_system(SYS_APPLY_VELOCITY);
	if (gamepad_button_b() == 1) run_system(SYS_SHOOT_LASER);
	run_system(SYS_CHECK_COLLISIONS);
	run_system(SYS_KEEP_ON_SCREEN);
	run_system(SYS_REMOVE_ABOVE_SCREEN);
	run_system(SYS_REMOVE_BELOW_SCREEN);
	run_system(SYS_DELAY_REMOVE);

	if (SpawnerTimer < 0)
	{
		SpawnerTimer = SPAWNER_INTERVAL + rand()%SPAWNER_INTERVAL_RANGE;
		Spawner();
	}
	else SpawnerTimer--;
}

void draw(void)
{
	set_multiply_color(color_white);
	clear_screen(color_black);

	DrawStarfield();

	run_system(SYS_DRAW_SPRITE);
}

void main(void)
{
	init();

	while (ContinueLoop)
	{
		update();
		draw();
		end_frame();
	}
}
