/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:01:09 by abelrodr          #+#    #+#             */
/*   Updated: 2023/11/07 14:33:34 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_image(t_game *game)
{
	game->wall_t = mlx_load_png("/Users/abelrodr/cursus/so_long/textures/wall.png");
	game->player_t = mlx_load_png("/Users/abelrodr/cursus/so_long/textures/player.png");
	game->coll_t = mlx_load_png("/Users/abelrodr/cursus/so_long/textures/collectible.png");
	game->exit_t = mlx_load_png("/Users/abelrodr/cursus/so_long/textures/exit.png");
	game->floor_t = mlx_load_png("/Users/abelrodr/cursus/so_long/textures/floor.png");
	game->couple_t = mlx_load_png("/Users/abelrodr/cursus/so_long/textures/couple.png");
	game->enemy_t = mlx_load_png("/Users/abelrodr/cursus/so_long/textures/enemy.png");
	game->back_t = mlx_load_png("/Users/abelrodr/cursus/so_long/textures/back.png");
	game->wall = mlx_texture_to_image(game->mlx, game->wall_t);
	mlx_delete_texture(game->wall_t);
	game->player = mlx_texture_to_image(game->mlx, game->player_t);
	mlx_delete_texture(game->player_t);
	game->coll->coll = mlx_texture_to_image(game->mlx, game->coll_t);
	mlx_delete_texture(game->coll_t);
	game->exitus = mlx_texture_to_image(game->mlx, game->exit_t);
	mlx_delete_texture(game->exit_t);
	game->floor = mlx_texture_to_image(game->mlx, game->floor_t);
	mlx_delete_texture(game->floor_t);
	game->couple = mlx_texture_to_image(game->mlx, game->couple_t);
	mlx_delete_texture(game->couple_t);
	game->enemy = mlx_texture_to_image(game->mlx, game->enemy_t);
	mlx_delete_texture(game->enemy_t);
	game->counter_back = mlx_new_image(game->mlx, 32, 32);
}

int	count_characters(char *buf)
{
	printf("Entering count_characters function\n");
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (buf[i])
	{
		if (buf[i] == 'E')
			e++;
		if (buf[i] == 'C')
			c++;
		if (buf[i] == 'P')
			p++;
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
		error_function(6);
	return (0);
}

int	count_n(char *buf, int c)
{
	char	n;
	int		i;
	int		count;

	i = 0;
	count = 1;
	n = (char)c;
	while (buf[i])
	{
		if (buf[i] == n)
			count++;
		i++;
	}
	return (count);
}
