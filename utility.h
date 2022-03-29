void GetCollectable(int actor, int actor2)
{
	//
}

void TakeDamage(int actor, int actor2)
{
	if ((Actors[actor] & COMP_HEALTH) && (Actors[actor2] & COMP_DEAL_DAMAGE))
	{
		C_Array_Health[actor] -= C_Array_DealDamage[actor2];

		if (C_Array_Health[actor] < 1)
		{
			SpawnExplosion(C_Array_Transform[actor].x, C_Array_Transform[actor].y);
			remove_actor(actor);
		}
	}
}
