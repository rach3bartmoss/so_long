#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "libraries/libft/libft.h"
# include "minilibx-linux/mlx.h"

# define TILE_SIZE 32
# define SPRITE_COUNT 6

# define MAX_ENEMIES 5

# define KEY_ESC 65307
# define X_EVENT_EXIT 17

typedef struct s_map
{
	int		width;//all ints 4 bytes, pointer 8 bytes
	int		height;
	int		collectibles;
	int		exit_count;
	int		player_count;
	int		player_y;
	int		player_x;
	char	**grid; //rearrange position to enhance data alignment
}				t_map;

typedef struct s_enemy
{
	//void	(*move)(struct s_data*, int);
	//void	(*handle_collision)(struct s_data*, int);
	int		y;
	int		x;
	int		alive;
}				t_enemy;

typedef struct s_sprite
{
	int		width;
	int		height;
	void	*img;
}				t_sprite;

//struct for image data
typedef struct s_data_img
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
}				t_data_img;

//struct for handle events
typedef struct s_data
{
	int			moves;
	int			enemy_count;
	t_map		map; //36 bytes
	t_data_img	image; //32 bytes
	t_sprite	sprites[SPRITE_COUNT]; // 16 x SPRITE_COUNT bytes
	t_enemy		enemies[MAX_ENEMIES]; // 12 x MAX_ENEMIES bytes
	void		*mlx;
	void		*win;
}				t_data;
//clean_close.c
int		clean_exit(t_data *data);
int		close_window_x_event(t_data *data);
int		key_exit_handler(int keycode, t_data *data);
//void	clean_map_grid(t_data *data);

int		init_data(t_data *data);

//map_loading.c
int		load_map(t_data *data, char *filename);
int		read_map_dimensions(t_data *data, char *filename);
int		init_map_memory(t_data *data);
void	cleanup_map(t_data *data);
int		cleanup_and_close(t_data *data, int fd);

//map_validation.c
int		validate_map(t_data *data);
int		count_map_elements(t_data *data);
int		check_map_borders(t_data *data);
int		validate_map_chars(char c);
void	init_map_elements(t_data *data, char c, int y, int x);

//render.c
int	get_sprite_index(char tile);
void	render_map(t_data *data);

//sprite_management.c
int	load_sprite(t_data *data, int index, char *path);
void cleanup_sprites(t_data *data);
int load_sprites(t_data *data);

//enemies_mechanics.c
void	init_enemies(t_data *data);
void	register_enemy(t_data *data, int y, int x);
int		is_position_valid(t_data *data, int y, int x);
void	update_enemy_positions(t_data *data);

//enemies_behavior.c
void	move_enemy(t_data *data, int enemy_index);
void	handle_collision(t_data *data, int enemy_index);
//void	handle_hit(t_data *data, int enemy_index);


#endif
