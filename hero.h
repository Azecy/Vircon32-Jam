void CreateHero(int x, int y)
{
	int hero_id = get_new_actor_id();

	if (hero_id < 0) return;

	Actors[hero_id] = (1 << COMP_ACTIVE);
	Actors[hero_id] |= (1 << COMP_COLLISION_GROUP);
	Actors[hero_id] |= (1 << COMP_COLLISION_MASK);
	Actors[hero_id] |= (1 << COMP_HEALTH);
	Actors[hero_id] |= (1 << COMP_KEEP_ON_SCREEN);
	Actors[hero_id] |= (1 << COMP_SHOOTS_LASER);
	Actors[hero_id] |= (1 << COMP_SPRITE);
	Actors[hero_id] |= (1 << COMP_TOP_DOWN_MOVE);
	Actors[hero_id] |= (1 << COMP_TRANSFORM);
	Actors[hero_id] |= (1 << COMP_VELOCITY);

	C_Array_Active[hero_id] = true;
	C_Array_CollisionGroup[hero_id] = (1 << CGRP_HERO);
	C_Array_CollisionMask[hero_id] = (1 << CGRP_ENEMY);
	C_Array_Health[hero_id] = 1;
	C_Array_ShootsLaser[hero_id] = WT_HERO_LASER;
	C_Array_Sprite[hero_id] = TX_REGION_HERO;
	C_Array_TopDownMove[hero_id].dirX = 0;
	C_Array_TopDownMove[hero_id].dirY = 0;
	C_Array_TopDownMove[hero_id].speed = HERO_SPEED;
	C_Array_Transform[hero_id].x = x;
	C_Array_Transform[hero_id].y = y;
	C_Array_Transform[hero_id].z = 0;
	C_Array_Transform[hero_id].w = TILE_SIZE*2;
	C_Array_Transform[hero_id].h = TILE_SIZE*2;
	C_Array_Velocity[hero_id].x = 0;
	C_Array_Velocity[hero_id].y = 0;
}

void CreateHeroLaser(int x, int y)
{
	int id = get_new_actor_id();

	if (id < 0) return;

	Actors[id] = (1 << COMP_ACTIVE);
	Actors[id] |= (1 << COMP_COLLISION_GROUP);
	Actors[id] |= (1 << COMP_DEAL_DAMAGE);
	Actors[id] |= (1 << COMP_REMOVE_ABOVE_SCREEN);
	Actors[id] |= (1 << COMP_SPRITE);
	Actors[id] |= (1 << COMP_TRANSFORM);
	Actors[id] |= (1 << COMP_VELOCITY);

	C_Array_Active[id] = true;
	C_Array_CollisionGroup[id] = (1 << CGRP_HERO_WEAPON);
	C_Array_DealDamage[id] = 1;
	C_Array_Sprite[id] = TX_REGION_LASER;
	C_Array_Transform[id].x = x;
	C_Array_Transform[id].y = y;
	C_Array_Transform[id].z = 0;
	C_Array_Transform[id].w = TILE_SIZE;
	C_Array_Transform[id].h = TILE_SIZE;
	C_Array_Velocity[id].x = 0;
	C_Array_Velocity[id].y = -HERO_LASER_SPEED;
}

void CreateOption(int x, int y)
{
	int id = get_new_actor_id();

	if (id < 0) return;

	Actors[id] = (1 << COMP_ACTIVE);
	Actors[id] |= (1 << COMP_SPRITE);
	Actors[id] |= (1 << COMP_TOP_DOWN_MOVE);
	Actors[id] |= (1 << COMP_TRANSFORM);
	Actors[id] |= (1 << COMP_VELOCITY);

	C_Array_Active[id] = true;
	C_Array_Sprite[id] = TX_REGION_OPTION;
	C_Array_TopDownMove[id].dirX = 0;
	C_Array_TopDownMove[id].dirY = 0;
	C_Array_TopDownMove[id].speed = HERO_SPEED;
	C_Array_Transform[id].x = x;
	C_Array_Transform[id].y = y;
	C_Array_Transform[id].z = 0;
	C_Array_Transform[id].w = TILE_SIZE;
	C_Array_Transform[id].h = TILE_SIZE;
	C_Array_Velocity[id].x = 0;
	C_Array_Velocity[id].y = 0;
}
