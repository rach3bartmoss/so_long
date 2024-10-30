#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <complex.h>
#include <mlx.h>
#include <unistd.h>

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (write(1, "Usage: <program> <map_name.ber>\n", 33));

	init_data(&data);
	if (!load_map(&data, argv[1]))
		return (write(1, "Error loading map\n", 18)); /* *********** */

	data.mlx = mlx_init();
	if (!data.mlx)
		return(clean_exit(&data));

	//Creates window
	data.win = mlx_new_window(data.mlx, data.map.width * TILE_SIZE, data.map.height * TILE_SIZE, "Diablo -1");
	if (!data.win)
		return (clean_exit(&data));

	//Hooks set ups for window closing w/or keyboard events
	mlx_hook(data.win, X_EVENT_EXIT, 0, close_window_x_event, &data);
	mlx_key_hook(data.win, key_exit_handler, &data);

	mlx_loop(data.mlx);

	return (clean_exit(&data));
}
