void system_apply_velocity(int actor)
{
	C_Array_Transform[actor].x += C_Array_Velocity[actor].x;
	C_Array_Transform[actor].y += C_Array_Velocity[actor].y;
}

void system_check_collisions(int actor)
{
	for (int i = 0; i < MAX_ACTORS; i++)
	{
		bool collision = false;

		if (((C_Array_CollisionMask[actor] & C_Array_CollisionGroup[i]) != 0) && (actor != i))
		{
			if ((C_Array_Transform[actor].x < (C_Array_Transform[i].x + C_Array_Transform[i].w) &&
				(C_Array_Transform[actor].x + C_Array_Transform[actor].w) > C_Array_Transform[i].x) &&
				(C_Array_Transform[actor].y < (C_Array_Transform[i].y + C_Array_Transform[i].h) &&
				(C_Array_Transform[actor].y + C_Array_Transform[actor].h) > C_Array_Transform[i].y))
			collision = true;
		}
		
		if (collision)
		{
			if ((Actors[actor] & (1 << COMP_HEALTH)) == (1 << COMP_HEALTH)) TakeDamage(actor, i);
			//GetCollectable(actor, i);
		}
	}
}

void system_draw_sprite(int actor)
{
	select_region(C_Array_Sprite[actor]);
	draw_region_at(C_Array_Transform[actor].x, C_Array_Transform[actor].y);
}

void system_keep_on_screen(int actor)
{
	if (C_Array_Transform[actor].x < 0)
	{
		C_Array_Transform[actor].x = 0;
	}
	if (C_Array_Transform[actor].x + C_Array_Transform[actor].w > screen_width)
	{
		C_Array_Transform[actor].x = screen_width - C_Array_Transform[actor].w;
	}
	if (C_Array_Transform[actor].y < 0)
	{
		C_Array_Transform[actor].y = 0;
	}
	if (C_Array_Transform[actor].y + C_Array_Transform[actor].h > screen_height)
	{
		C_Array_Transform[actor].y = screen_height - C_Array_Transform[actor].h;
	}
}

void system_remove_above_screen(int actor)
{
	if (C_Array_Transform[actor].y + C_Array_Transform[actor].h < 0)
	{
		remove_actor(actor);
	}
}

void system_remove_below_screen(int actor)
{
	if (C_Array_Transform[actor].y > screen_height)
	{
		remove_actor(actor);
	}
}

void system_shoot_laser(int actor)
{
	if (C_Array_ShootsLaser[actor] == WT_HERO_LASER)
	{
		CreateHeroLaser(C_Array_Transform[actor].x + TILE_SIZE, C_Array_Transform[actor].y - TILE_SIZE - 1);
	}
}

void system_top_down_move(int actor)
{
	gamepad_direction(&C_Array_TopDownMove[actor].dirX, &C_Array_TopDownMove[actor].dirY);
	C_Array_Velocity[actor].x = C_Array_TopDownMove[actor].dirX*C_Array_TopDownMove[actor].speed;
	C_Array_Velocity[actor].y = C_Array_TopDownMove[actor].dirY*C_Array_TopDownMove[actor].speed;
}

void system_delay_remove(int actor)
{
	C_Array_DelayRemove[actor] -= 1;
	if (C_Array_DelayRemove[actor] < 1)
	{
		remove_actor(actor);
	}
}

// -----------------------------------------------
void run_system(System sys)
{
	int requiredComponents = (1 << COMP_ACTIVE);

	// Define the required components for each system
	if (sys == SYS_DRAW_SPRITE)
	{
		requiredComponents |= (1 << COMP_SPRITE);
		requiredComponents |= (1 << COMP_TRANSFORM);
	}
	else if (sys == SYS_CHECK_COLLISIONS)
	{
		requiredComponents |= (1 << COMP_COLLISION_MASK);
		requiredComponents |= (1 << COMP_TRANSFORM);
	}
	else if (sys == SYS_DELAY_REMOVE)
	{
		requiredComponents |= (1 << COMP_DELAY_REMOVE);
	}
	else if (sys == SYS_KEEP_ON_SCREEN)
	{
		requiredComponents |= (1 << COMP_KEEP_ON_SCREEN);
		requiredComponents |= (1 << COMP_TRANSFORM);
	}
	else if (sys == SYS_REMOVE_ABOVE_SCREEN)
	{
		requiredComponents |= (1 << COMP_REMOVE_ABOVE_SCREEN);
		requiredComponents |= (1 << COMP_TRANSFORM);
	}
	else if (sys == SYS_REMOVE_BELOW_SCREEN)
	{
		requiredComponents |= (1 << COMP_REMOVE_BELOW_SCREEN);
		requiredComponents |= (1 << COMP_TRANSFORM);
	}
	else if (sys == SYS_SHOOT_LASER)
	{
		requiredComponents |= (1 << COMP_SHOOTS_LASER);
		requiredComponents |= (1 << COMP_TRANSFORM);
	}
	else if (sys == SYS_TOP_DOWN_MOVE)
	{
		requiredComponents |= (1 << COMP_SPRITE);
		requiredComponents |= (1 << COMP_TOP_DOWN_MOVE);
		requiredComponents |= (1 << COMP_TRANSFORM);
		requiredComponents |= (1 << COMP_VELOCITY);
	}
	else if (sys == SYS_APPLY_VELOCITY)
	{
		requiredComponents |= (1 << COMP_TRANSFORM);
		requiredComponents |= (1 << COMP_VELOCITY);
	}
	else // error
	{
		return;
	}

	// Run the system associated with the parameter
	for (int i = 0; i < MAX_ACTORS; i++)
	{
		if ((Actors[i] & requiredComponents) == requiredComponents)
		{
			if (sys == SYS_DRAW_SPRITE)
			{
				system_draw_sprite(i);
			}
			else if (sys == SYS_CHECK_COLLISIONS)
			{
				system_check_collisions(i);
			}
			else if (sys == SYS_DELAY_REMOVE)
			{
				system_delay_remove(i);
			}
			else if (sys == SYS_KEEP_ON_SCREEN)
			{
				system_keep_on_screen(i);
			}
			else if (sys == SYS_REMOVE_ABOVE_SCREEN)
			{
				system_remove_above_screen(i);
			}
			else if (sys == SYS_REMOVE_BELOW_SCREEN)
			{
				system_remove_below_screen(i);
			}
			else if (sys == SYS_SHOOT_LASER)
			{
				system_shoot_laser(i);
			}
			else if (sys == SYS_TOP_DOWN_MOVE)
			{
				system_top_down_move(i);
			}
			else if (sys == SYS_APPLY_VELOCITY)
			{
				system_apply_velocity(i);
			}
		}
	}
}
