/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:22:40 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/15 17:06:40 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define LENGTH_MAX 500
# define WIDTH_MAX 500
# define PLAYER_MAX 10
# define DEFAULT_COLOR 0x000000
# define PLAYER_COLOR 0xFF0000

typedef struct s_player {
	int	x;
	int	y;
	int	color;
}				t_player;

typedef struct s_vars {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int player_number;
    t_player *players;
} t_vars;


// color-related functions
int				create_trgb(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

// hook-related functions.;
int				close_window(t_vars *vars);
int				player_movement(int keycode, t_vars *vars);
int				mouse_inputs(int button, int x, int y, t_vars *vars);

// color manipulation exercises
void 			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int				add_shade(double distance, int color);
int				get_opposite(int color);
//void			my_mlx_area_put(t_data *data, int color);

//image functions
int				clear_and_reset(t_vars *vars);

#endif