/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:02:50 by abelrodr          #+#    #+#             */
/*   Updated: 2023/10/31 16:31:55 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_function(int i)
{
	if (i == 1)
		ft_printf("Error\nwrong map file format\n");
	else if (i == 2)
		ft_printf("Error\nwrong map file descriptor\n");
	else if (i == 3)
		ft_printf("Error\nempty map file\n");
	else if (i == 4)
		ft_printf("Error:\nmap is not valid or is not surrounded by borders\n");
	else if (i == 5)
		ft_printf("Error:\nmap contains invalid characters\n");
	else if (i == 6)
		ft_printf("Error:\ninvalid number of characters\n");
	else if (i == 7)
		ft_printf("Error:\nsome collectibles or the exit are not accesible\n");
	exit(1);
}

void	path_finder(t_game *game)
{
	int	i;
	int	y;

	y = 0;
	while (y < game->h)
	{
		i = 0;
		while (i < game->w)
		{
			if (game->grid[y][i] == 'P')
			{
				flood_fill(game, y, i);
				if (game->flood_c != game->c || game->flood_e != game->e)
				{
					error_function(7);
					cleaning(game);
					exit(1);
				}
				cleaning(game);
				return ;
			}
			i++;
		}
		y++;
	}
}

void	flood_fill(t_game *game, int y, int i)
{
	if (game->grid[y][i] == 'f' || game->grid[y][i] == '1'
		|| game->grid[y][i] == 'X')
		return ;
	if (game->grid[y][i] == 'E')
		game->flood_e++;
	if (game->grid[y][i] == 'C')
		game->flood_c++;
	game->grid[y][i] = 'f';
	flood_fill(game, y + 1, i);
	flood_fill(game, y - 1, i);
	flood_fill(game, y, i + 1);
	flood_fill(game, y, i - 1);
}

void	bonus_count(t_game *game)
{
	char	*counter;

	counter = ft_itoa(game->count);
	mlx_delete_image(game->mlx, game->counter_back);
	game->counter_back = mlx_put_string(game->mlx, counter, 2, 6);
	free(counter);
	counter = NULL;
}

void	beaten_by_husband(t_game *game)
{
	game->player->instances[0].enabled = 0;
	ft_printf("We never win Worlds :(\n");
	ft_printf("GAME LOST!\n");
	final_cleaning(game);
}
