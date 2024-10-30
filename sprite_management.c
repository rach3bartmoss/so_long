#include "so_long.h"

int	load_sprite(t_data *data, int index, char *path)
{
	int width;
	int height;

	data->sprites[index].img = mlx_xpm_file_to_image(data->mlx,
		path, &width, &height);

	if (!data->sprites[index].img)
		return (0);

	data->sprites[index].width = width;
	data->sprites[index].height = height;
	return (1);
}

void cleanup_sprites(t_data *data)
{
	int i;

	i = 0;
	while (i < SPRITE_COUNT)
	{
		if (data->sprites[i].img)
			mlx_destroy_image(data->mlx, data->sprites[i].img);
		i++;
	}
}

int load_sprites(t_data *data)
{
	if (!load_sprite(data, 0, "sprites/wall.xpm") ||
		!load_sprite(data, 1, "sprites/floor.xpm") ||
		!load_sprite(data, 2, "sprites/player.xpm") ||
		!load_sprite(data, 3, "sprites/exit.xpm") ||
		!load_sprite(data, 4, "sprites/collectible.xpm"))
	{
		cleanup_sprites(data);
		return (0);
	}
	return (1);
}
