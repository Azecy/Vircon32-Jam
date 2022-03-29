void SpawnExplosion(int x, int y)
{
	int id = get_new_actor_id();
	if (id < 0) return;

	Actors[id] = (1 << COMP_ACTIVE);
	Actors[id] |= (1 << COMP_DELAY_REMOVE);
	Actors[id] |= (1 << COMP_SPRITE);
	Actors[id] |= (1 << COMP_TRANSFORM);

	C_Array_Active[id] = true;
	C_Array_DelayRemove[id] = 60;
	C_Array_Sprite[id] = TX_REGION_EXPLOSION;
	C_Array_Transform[id].x = x;
	C_Array_Transform[id].y = y;
	C_Array_Transform[id].z = 0;
	C_Array_Transform[id].w = TILE_SIZE*1;
	C_Array_Transform[id].h = TILE_SIZE*1;
}

void SpawnOptionPickup(int x, int y)
{
	int id = get_new_actor_id();
	if (id < 0) return;
}

void SpawnCoin(int x, int y)
{
	int id = get_new_actor_id();
	if (id < 0) return;
}
