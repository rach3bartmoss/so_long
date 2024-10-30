#include "so_long.h"

void	init_enemies(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	data->enemy_count = 0; //updated in register enemy
	while (y < data->map.height)
	{
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == 'F')
				register_enemy(data, y, x);
			x++;
		}
		y++;
	}
}

void	register_enemy(t_data *data, int y, int x)
{
	if (data->enemy_count < MAX_ENEMIES)
	{
		data->enemies[data->enemy_count].y = y;
		data->enemies[data->enemy_count].x = x;
		data->enemies[data->enemy_count].alive = 1;
		data->enemies[data->enemy_count].move = (void (*)(struct s_data*, int))move_enemy;
		data->enemies[data->enemy_count].handle_collision = (void (*)(struct s_data*, int))handle_collision;
		data->enemy_count++;
	}
}

//checks if the pos is within the boundaries of the map
//check if the pos is not a wall
int	is_position_valid(t_data *data, int y, int x)
{
	if (y < 0 || y >= data->map.height)
		return (0);
	if (x < 0 || x >= data->map.width)
		return (0);
	if (data->map.grid[y][x] == '1')
		return (0);
	return (1);
}

void	update_enemy_positions(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		if (data->enemies[i].alive == 1)
		{
			data->enemies[i].move(data, i);
			if (data->map.player_x == data->enemies[i].x && data->map.player_y == data->enemies[i].y)
				data->enemies[i].handle_collision(data, i);
		}
		i++;
	}
}
