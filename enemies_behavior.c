#include "so_long.h"

void	handle_collision(t_data *data, int enemy_index)
{
	data->map.player_count = 0;
}

void	move_enemy(t_data *data, int enemy_index)
{
	static int	dx[] = {0, 1, 0, -1};
	static int	dy[] = {1, 0, -1, 0};
	int			direction;
	int			new_x;
	int			new_y;

	direction = rand() % 4;
	new_x = data->enemies[enemy_index].x + dx[direction];
	new_y = data->enemies[enemy_index].y + dy[direction];
	if (is_position_valid(data, new_y, new_x))
	{
		data->enemies[enemy_index].x = new_x;
		data->enemies[enemy_index].y = new_y;
	}
}
