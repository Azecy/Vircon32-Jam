int get_new_actor_id(void)
{
	if (DeadActorCount > 0)
	{
		DeadActorCount--;
		return DeadActorArray[DeadActorCount];
	}
	else if (HighestActorID + 1 < MAX_ACTORS)
	{
		HighestActorID++;
		return HighestActorID;
	}
	else // Max amount of actors exist
	{
		return -1; // error: please handle this case after the function returns
	}
}

void remove_actor(int ActorID)
{
	if (DeadActorCount >= MAX_ACTORS) return; // error: this should be impossible
	if ((ActorID >= MAX_ACTORS) || (ActorID < 0)) return; // error: bad parameter

	if (Actors[ActorID] != 0) // Make sure the actor hasn't aleady been removed
	{
		Actors[ActorID] = 0;
		C_Array_Active[ActorID] = false;

		DeadActorArray[DeadActorCount] = ActorID;
		DeadActorCount++;
	}
}

void init_ecs(void)
{
	HighestActorID = -1;
	DeadActorCount = 0;

	for (int i = 0; i < MAX_ACTORS; i++)
	{
		Actors[i] = 0; // No components
		C_Array_Active[i] = false;
	}
}
