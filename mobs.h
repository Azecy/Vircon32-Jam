void CreateMine(int x, int y)
{
	int id = get_new_actor_id();
	if (id < 0) return;

	Actors[id] = (1 << COMP_ACTIVE);
	Actors[id] |= (1 << COMP_COLLISION_GROUP);
	Actors[id] |= (1 << COMP_COLLISION_MASK);
	Actors[id] |= (1 << COMP_DEAL_DAMAGE);
	Actors[id] |= (1 << COMP_HEALTH);
	Actors[id] |= (1 << COMP_REMOVE_BELOW_SCREEN);
	Actors[id] |= (1 << COMP_SPRITE);
	Actors[id] |= (1 << COMP_TRANSFORM);
	Actors[id] |= (1 << COMP_VELOCITY);

	C_Array_Active[id] = true;
	C_Array_CollisionGroup[id] = (1 << CGRP_ENEMY);
	C_Array_CollisionMask[id] = (1 << CGRP_HERO_WEAPON);
	C_Array_DealDamage[id] = 1;
	C_Array_Health[id] = 1;
	C_Array_Sprite[id] = TX_REGION_MINE;
	C_Array_Transform[id].x = x;
	C_Array_Transform[id].y = y;
	C_Array_Transform[id].z = 0;
	C_Array_Transform[id].w = TILE_SIZE;
	C_Array_Transform[id].h = TILE_SIZE;
	C_Array_Velocity[id].x = 0;
	C_Array_Velocity[id].y = 3;
}

void CreateSmallEnemy(int x, int y)
{
	int id = get_new_actor_id();
	if (id < 0) return;

	Actors[id] = (1 << COMP_ACTIVE);
	Actors[id] |= (1 << COMP_COLLISION_GROUP);
	Actors[id] |= (1 << COMP_COLLISION_MASK);
	Actors[id] |= (1 << COMP_DEAL_DAMAGE);
	Actors[id] |= (1 << COMP_HEALTH);
	Actors[id] |= (1 << COMP_REMOVE_BELOW_SCREEN);
	Actors[id] |= (1 << COMP_SPRITE);
	Actors[id] |= (1 << COMP_TRANSFORM);
	Actors[id] |= (1 << COMP_VELOCITY);

	C_Array_Active[id] = true;
	C_Array_CollisionGroup[id] = (1 << CGRP_ENEMY);
	C_Array_CollisionMask[id] = (1 << CGRP_HERO_WEAPON);
	C_Array_DealDamage[id] = 1;
	C_Array_Health[id] = 1;
	C_Array_Sprite[id] = TX_REGION_ENEMY_SMALL;
	C_Array_Transform[id].x = x;
	C_Array_Transform[id].y = y;
	C_Array_Transform[id].z = 0;
	C_Array_Transform[id].w = TILE_SIZE;
	C_Array_Transform[id].h = TILE_SIZE;
	C_Array_Velocity[id].x = 0;
	C_Array_Velocity[id].y = 4;
}

void CreateBigEnemy(int x, int y)
{
	int id = get_new_actor_id();
	if (id < 0) return;

	Actors[id] = (1 << COMP_ACTIVE);
	Actors[id] |= (1 << COMP_COLLISION_GROUP);
	Actors[id] |= (1 << COMP_COLLISION_MASK);
	Actors[id] |= (1 << COMP_DEAL_DAMAGE);
	Actors[id] |= (1 << COMP_HEALTH);
	Actors[id] |= (1 << COMP_REMOVE_BELOW_SCREEN);
	Actors[id] |= (1 << COMP_SPRITE);
	Actors[id] |= (1 << COMP_TRANSFORM);
	Actors[id] |= (1 << COMP_VELOCITY);

	C_Array_Active[id] = true;
	C_Array_CollisionGroup[id] = (1 << CGRP_ENEMY);
	C_Array_CollisionMask[id] = (1 << CGRP_HERO_WEAPON);
	C_Array_DealDamage[id] = 1;
	C_Array_Health[id] = 1;
	C_Array_Sprite[id] = TX_REGION_ENEMY_BIG;
	C_Array_Transform[id].x = x;
	C_Array_Transform[id].y = y;
	C_Array_Transform[id].z = 0;
	C_Array_Transform[id].w = TILE_SIZE*4;
	C_Array_Transform[id].h = TILE_SIZE*4;
	C_Array_Velocity[id].x = 0;
	C_Array_Velocity[id].y = 3;
}

void Spawner(void)
{
	int random = rand()%3;

	if (random == 0)
	{
		CreateMine(rand()%screen_width, 0);
	}
	else if (random == 1)
	{
		CreateSmallEnemy(rand()%screen_width, 0);
	}
	else if (random == 2)
	{
		CreateBigEnemy(rand()%screen_width, 0);
	}
}
