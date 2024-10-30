#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	get_sprite_index(char tile)
{
	if (tile == '1')
		return (0);
	if (tile == '0')
		return (1);
	if (tile == 'P')
		return (2);
	if (tile == 'E')
		return (3);
	if (tile == 'C')
		return (4);
	return (-1);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;
	int	sprite_index;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			sprite_index = get_sprite_index(data->map.grid[y][x]);
			if (sprite_index >= 0)
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->sprites[sprite_index].img,
					x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
