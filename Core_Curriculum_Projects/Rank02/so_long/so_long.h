/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:22:40 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/20 17:42:34 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYER_MAX 10
# define DEFAULT_COLOR 0x000000
# define PLAYER_COLOR 0xFF0000
# define OBJECTS_SIZE 50

typedef struct s_sprites {
	void	*floor_xpm;
	void	*barrier_xpm;
	void	*collectible_xpm;
	void	*danger_xpm;
	//void	*exit_xpm;
}	t_sprites;

typedef struct s_player {
	int		x;
	int		y;
	int		health;
	void	*player_xpm;
}	t_player;

typedef struct s_exit {
	int		x;
	int		y;
	void	*exit_xpm;
}	t_exit;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	int			**map_visited;
	int			x_max;
	int			y_max;
	int			fd;
	int			player_number;
	int			collectible_count;
	int			moves;
	t_player	*player;
	t_sprites	*sprites;
	t_exit		*exit;
}	t_vars;


// hook-related functions.;
int				close_window(t_vars *vars);
int				player_movement(int keycode, t_vars *vars);
int				mouse_inputs(int button, int x, int y, t_vars *vars);

// color manipulation exercises
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

//image functions
void			create_map(t_vars *vars);

//sprite_initialization
void			put_floor(t_vars *vars, int x, int y);
void			put_barrier(t_vars *vars, int x, int y);
void			put_danger(t_vars *vars, int x, int y);
void			put_exit(t_vars *vars, int x, int y);
void			put_player(t_vars *vars, int x, int y);
void			put_collectible(t_vars *vars, int x, int y);

// error handling
void			check_map(t_vars *vars);
void			error_messaging(t_vars *vars, int error_number);
void			check_for_rectangle(t_vars *vars);
void			check_for_exit(t_vars *vars);
void			check_for_player_collectible(t_vars *vars);
void			check_for_walls(t_vars *vars);
int				check_for_path(t_vars *vars, int player_x, int player_y);

#endif