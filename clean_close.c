#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <mlx.h>

int	clean_exit(t_data *data)
{
	//1) DESTROY IMAGE IF IT EXISTS
	if (data && data->image.img)
	{
		mlx_destroy_image(data->mlx, data->image.img);
		data->image.img = NULL;
		data->image.addr = NULL;
	}
	//2)DESTROY WINDOW IF IT EXISTS
	if (data && data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	//3) CLEAN MLX_INIT() TARGET IF IT EXISTS
	if (data && data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	//cleans up map grid allocated by init_map_memory "map_loading"
	cleanup_map(data);
	exit (0);
	return (0);
}

int	close_window_x_event(t_data *data)
{
	clean_exit(data);
	return (0);
}

int	key_exit_handler(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		clean_exit (data);
	return (0);
}

/*void	clean_map_grid(t_data *data)
{
	int	i;

	while (i < data->map.height)
	{
		free(data->map.grid[i]);
		i++;
	}
	free(data->map.grid);
}
*/
