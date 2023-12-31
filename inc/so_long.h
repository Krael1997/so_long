/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:49:49 by abelrodr          #+#    #+#             */
/*   Updated: 2023/11/07 15:33:02 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* LIBS */

// Personal Libs
# include "../libs/libft/inc/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
// System Libs
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

/* STRUCT */
typedef struct s_map
{
	int	total_char;
	int	lenght;
	int	height;
	int	consistence;
}	t_map;

typedef struct s_coll
{
	mlx_image_t	*coll;
	int			pos_x;
	int			pos_y;
	int			o;
}	t_coll;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*player_t;
	mlx_texture_t	*coll_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*floor_t;
	mlx_texture_t	*couple_t;
	mlx_texture_t	*enemy_t;
	mlx_texture_t	*back_t;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*exitus;
	mlx_image_t		*floor;
	mlx_image_t		*couple;
	mlx_image_t		*enemy;
	mlx_image_t		*counter_back;
	mlx_image_t		*back;
	t_coll			*coll;
	char			**grid;
	int				w;
	int				h;
	int				c;
	int				e;
	int				p;
	int				collectibles;
	int				p_pos_h;
	int				p_pos_l;
	int				flood_c;
	int				flood_e;
	int				count;
}	t_game;

int			count_characters(char *buf);
int			count_n(char *buf, int c);
int			integrity_check(char *buf);
int			map_borders(t_map *map, char *buf);
int			map_check(char *filename);
int			suffix_check(char *filename);
int			game_start(t_map *map, char *buf);
void		key_hook(mlx_key_data_t keydata, void *param);	
void		render_map(t_game *game, t_map *map);
void		load_image(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		char_count_2(t_game *game, char *buf);
void		render_map_game(t_game *game);
void		collect(t_game *game);
void		path_finder(t_game *game);
void		game_init(t_game *game);
void		flood_fill(t_game *game, int y, int i);
void		map_init(t_map *map);
void		error_function(int i);
void		final_cleaning(t_game *game);
void		cleaning(t_game *game);
void		put_collectible(t_game *game, int y, int i);
void		map_consistence(t_map *map, char *buf);
void		while_function(t_game *game, t_map *map, int y, int i);
void		player_rendering(t_game *game, int y, int i);
void		game_lost(t_game *game);
void		bonus_count(t_game *game);
void		emergency_cleaning(t_game *game);

#endif
