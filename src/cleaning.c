/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:45:32 by abelrodr          #+#    #+#             */
/*   Updated: 2023/10/24 16:47:58 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	emergency_cleaning(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->h)
	{
		free(game->grid[x]);
		game->grid[x] = NULL;
		x++;
	}
	free(game->grid);
	game->grid = NULL;
	free(game->coll);
	game->coll = NULL;
}

void	cleaning(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->h)
	{
		free(game->grid[x]);
		game->grid[x] = NULL;
		x++;
	}
	free(game->grid);
	game->grid = NULL;
}

void	final_cleaning(t_game *game)
{
	cleaning(game);
	free(game->coll);
	game->coll = NULL;
	game->counter_back = NULL;
	mlx_close_window(game->mlx);
}
