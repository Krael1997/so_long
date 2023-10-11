/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:43:37 by abelrodr          #+#    #+#             */
/*   Updated: 2023/10/11 19:23:12 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	error(void)
{
	if (ft_strcmp(mlx_strerror(mlx_errno), "No errors") == 0)
	{
		ft_printf(mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(param);
}

int	main(void)
{
	mlx_t			*mlx;
	int32_t			width;
	int32_t			height;
	mlx_texture_t	*cubo;
	mlx_image_t		*img_cubo;

	width = 800;
	height = 600;
	mlx = mlx_init(width, height, "so_long", true);
	cubo = mlx_load_png("img/Grass_Block_JE4.png");
	img_cubo = mlx_texture_to_image(mlx, cubo);
	if (!mlx)
		error();
	if (!cubo)
		error();
	if (!img_cubo)
		error();
	if (mlx_image_to_window(mlx, img_cubo, 0, 0) == 0)
		error();
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img_cubo);
	mlx_delete_texture(cubo);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
