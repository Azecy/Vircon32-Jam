#define STARS_SMALL 100
#define STARS_LARGE 20
#define STAR_SMALL_SPEED_MIN 4
#define STAR_SMALL_SPEED_RANGE 2
#define STAR_LARGE_SPEED_MIN 2
#define STAR_LARGE_SPEED_RANGE 2

struct Star
{
	int speed;
	int x;
	int y;
};

Star[STARS_SMALL] small_stars;
Star[STARS_LARGE] large_stars;

void InitStarfield(void)
{
	for (int i = 0; i < STARS_SMALL; i++)
	{
		small_stars[i].speed = STAR_SMALL_SPEED_MIN + rand()%STAR_SMALL_SPEED_RANGE;
		small_stars[i].x = rand()%screen_width;
		small_stars[i].y = rand()%screen_height;
	}
	for (int i = 0; i < STARS_LARGE; i++)
	{
		large_stars[i].speed = STAR_LARGE_SPEED_MIN + rand()%STAR_LARGE_SPEED_RANGE;
		large_stars[i].x = rand()%screen_width;
		large_stars[i].y = rand()%screen_height;
	}
}

void UpdateStarfield(void)
{
	for (int i = 0; i < STARS_SMALL; i++)
	{
		small_stars[i].y += small_stars[i].speed;
		if (small_stars[i].y > screen_height)
		{
			small_stars[i].speed = STAR_SMALL_SPEED_MIN + rand()%STAR_SMALL_SPEED_RANGE;
			small_stars[i].x = rand()%screen_width;
			small_stars[i].y = 0;
		}
	}
	for (int i = 0; i < STARS_LARGE; i++)
	{
		large_stars[i].y += large_stars[i].speed;
		if (large_stars[i].y > screen_height)
		{
			large_stars[i].speed = STAR_LARGE_SPEED_MIN + rand()%STAR_LARGE_SPEED_RANGE;
			large_stars[i].x = rand()%screen_width;
			large_stars[i].y = 0;
		}
	}
}

void DrawStarfield(void)
{
	select_region(TX_REGION_WHITE_1X1);
	for (int i = 0; i < STARS_SMALL; i++)
	{
		draw_region_at(small_stars[i].x, small_stars[i].y);
	}
	
	select_region(TX_REGION_WHITE_2X2);
	for (int i = 0; i < STARS_LARGE; i++)
	{
		draw_region_at(large_stars[i].x, large_stars[i].y);
	}
}
