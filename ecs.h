// -----------------------------------------------
// ECS setup
// -----------------------------------------------
#define MAX_ACTORS 256
typedef int Actor;


// -----------------------------------------------
// Components
// -----------------------------------------------
enum Component
{
	COMP_ACTIVE,
	COMP_COLLISION_GROUP,
	COMP_COLLISION_MASK,
	COMP_DEAL_DAMAGE,
	COMP_DELAY_REMOVE,
	COMP_HEALTH,
	COMP_KEEP_ON_SCREEN,
	COMP_REMOVE_ABOVE_SCREEN,
	COMP_REMOVE_BELOW_SCREEN,
	COMP_SHOOTS_LASER,
	COMP_SPRITE,
	COMP_TOP_DOWN_MOVE,
	COMP_TRANSFORM,
	COMP_VELOCITY,

	NUMBER_OF_COMPONENTS
};
// -----------------------------------------------
enum CollisionGroup
{
	CGRP_ENEMY,
	CGRP_HERO,
	CGRP_HERO_WEAPON,

	NUMBER_OF_COLLISION_GROUPS
};
// -----------------------------------------------
enum WeaponType
{
	WT_HERO_LASER,

	NUMBER_OF_WEAPON_TYPES
};
// -----------------------------------------------

typedef bool C_Active;

typedef int C_CollisionGroup;

typedef int C_CollisionMask;

typedef int C_DealDamage;

typedef int C_DelayRemove;

typedef int C_Health;

typedef int C_ShootsLaser;

typedef int C_Sprite;

struct C_TopDownMove
{
	int dirX, dirY;
	int speed;
};

struct C_Transform
{
	int x, y, z;
	int w, h;
};

struct C_Velocity
{
	int x, y;
};


// -----------------------------------------------
// Global variables
// -----------------------------------------------
Actor[MAX_ACTORS] Actors;
C_Active[MAX_ACTORS] C_Array_Active;
C_CollisionGroup[MAX_ACTORS] C_Array_CollisionGroup;
C_CollisionMask[MAX_ACTORS] C_Array_CollisionMask;
C_DealDamage[MAX_ACTORS] C_Array_DealDamage;
C_DelayRemove[MAX_ACTORS] C_Array_DelayRemove;
C_Health[MAX_ACTORS] C_Array_Health;
C_ShootsLaser[MAX_ACTORS] C_Array_ShootsLaser;
C_Sprite[MAX_ACTORS] C_Array_Sprite;
C_TopDownMove[MAX_ACTORS] C_Array_TopDownMove;
C_Transform[MAX_ACTORS] C_Array_Transform;
C_Velocity[MAX_ACTORS] C_Array_Velocity;

int HighestActorID;
int DeadActorCount;
int[MAX_ACTORS] DeadActorArray; // Stores dead actor IDs for re-use


// -----------------------------------------------
// Systems
// -----------------------------------------------
enum System
{
	SYS_APPLY_VELOCITY,
	SYS_CHECK_COLLISIONS,
	SYS_DEAL_DAMAGE,
	SYS_DELAY_REMOVE,
	SYS_DRAW_SPRITE,
	SYS_KEEP_ON_SCREEN,
	SYS_REMOVE_ABOVE_SCREEN,
	SYS_REMOVE_BELOW_SCREEN,
	SYS_SHOOT_LASER,
	SYS_TOP_DOWN_MOVE,

	NUMBER_OF_SYSTEMS
};
