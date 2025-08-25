/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:42:24 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/25 22:20:21 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	get_map_width(char **map)
{
	return (ft_strlen(map[0]));
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img_fl);
	mlx_destroy_image(game->mlx, game->img_wa);
	mlx_destroy_image(game->mlx, game->img_pl);
	mlx_destroy_image(game->mlx, game->img_co);
	mlx_destroy_image(game->mlx, game->img_ex);
	mlx_destroy_display(game->mlx);
	free_array(game->map);
	ft_printf("Game closed.\n");
	exit(0);
	return (0);
}
