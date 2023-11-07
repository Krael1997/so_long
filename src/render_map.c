/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:24:28 by abelrodr          #+#    #+#             */
/*   Updated: 2023/11/07 14:46:08 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collect(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->collectibles)
	{
		if (game->coll->coll->instances[i].x == game->player->instances[0].x
			&& game->coll->coll->instances[i].y == game->player->instances[0].y)
			game->coll->coll->instances[i].enabled = 0;
		i++;
	}
	if (game->c == 0)
	{
		game->player->instances[0].enabled = 0;
		game->couple->instances[0].enabled = 1;
		game->exitus->instances[0].enabled = 1;
	}
}

void	put_collectible(t_game *game, int y, int i)
{
	mlx_image_to_window(game->mlx, game->coll->coll, (y * 32), (i * 32));
}

void	player_rendering(t_game *game, int y, int i)
{
	mlx_image_to_window(game->mlx, game->couple, (y * 32), (i * 32));
	game->couple->instances[0].enabled = 0;
	mlx_image_to_window(game->mlx, game->player, (y * 32), (i * 32));
	game->p_pos_h = i;
	game->p_pos_l = y;
}

void	while_function(t_game *game, t_map *map, int y, int i)
{
	i = 0;
	while (i < map->height)
	{
		y = 0;
		while (y < map->lenght)
		{
			if (game->grid[i][y] == '1')
				mlx_image_to_window(game->mlx, game->wall, (y * 32), (i * 32));
			else if (game->grid[i][y] == 'E')
			{
				mlx_image_to_window(game->mlx, \
				game->exitus, (y * 32), (i * 32));
				game->exitus->instances[0].enabled = 0;
			}
			else if (game->grid[i][y] == 'C')
				put_collectible(game, y, i);
			else if (game->grid[i][y] == 'P')
				player_rendering(game, y, i);
			else if (game->grid[i][y] == 'X')
				mlx_image_to_window(game->mlx, game->enemy, (y * 32), (i * 32));
			y++;
		}
		i++;
	}
}

void	render_map(t_game *game, t_map *map)
{
	printf("Rendering map\n");
	int	i;
	int	y;

	load_image(game);
	printf("Image loaded\n");
	i = 0;
	while (i < (map->height - 1))
	{
		y = 0;
		while (y < (map->lenght - 1))
		{
			mlx_image_to_window(game->mlx, game->floor, (y * 32), (i * 32));
			y++;
		}
		i++;
	}
	printf("Floor rendered\n");
	i = 0;
	while_function(game, map, y, i);
	printf("Map rendered\n");
	//mlx_image_to_window(game->mlx, game->back, 0, 0);
	//printf("Back rendered\n");
}
