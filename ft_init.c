#include "so_long.h"

int	init_data(t_data *data)
{
	if (!data)
		return (0);
	data->mlx = NULL;
	data->win = NULL;

	// Initialize image structure
	data->image.img = NULL;
	data->image.addr = NULL;
	data->image.bits_per_pixel = 0;
	data->image.line_length = 0;
	data->image.endian = 0;

	return (1);
}
