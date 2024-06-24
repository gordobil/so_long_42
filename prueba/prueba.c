# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include "../mlx/mlx.h"
# define SQ 64
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define L_ARROW 65361
# define R_ARROW 65363
# define U_ARROW 65362
# define D_ARROW 65364

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;

void	put_counter(t_data *data, char *n)
{
	int	y;
	int	x;
	int	col;

	col = 0x00CAE4EB;
	y = 5;
	while (y < 20)
	{
		x = 5;
		while (x < 36)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x00005B99);
			x++;
		}
		y++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 18, 17, col, n);
}

int	handle_no_event(void *data)
{
    /* This function needs to exist, but it is useless for the moment */
    return (0);
}

int	handle_input(int keysym, t_data *data)
{
    if (keysym == ESC || keysym == Q)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	else if (keysym == W || keysym == U_ARROW)
		put_counter(data, "W");
	else if (keysym == S || keysym == D_ARROW)
		put_counter(data, "S");
    return (0);
}

int	main(void)
{
    t_data	data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 200, 200,
            "My first window!");

    /* Setup hooks */ 
    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
    mlx_key_hook(data.win_ptr, &handle_input, &data);

    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}