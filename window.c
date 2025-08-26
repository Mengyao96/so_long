/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:42:24 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/26 18:52:27 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	launch_win(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->mp_wd = get_map_width(game->map);
	game->mp_ht = get_map_height(game->map);
	game->win = mlx_new_window(game->mlx, game->mp_wd * 32, game->mp_ht * 32,
			"Galaxy_23");
	if (!game->win)
		return (mlx_destroy_display(game->mlx), free(game->mlx), -1);
	return (0);
}

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
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img_bg)
		mlx_destroy_image(game->mlx, game->img_bg);
	if (game->img_fl)
		mlx_destroy_image(game->mlx, game->img_fl);
	if (game->img_wa)
		mlx_destroy_image(game->mlx, game->img_wa);
	if (game->img_pl)
		mlx_destroy_image(game->mlx, game->img_pl);
	if (game->img_co)
		mlx_destroy_image(game->mlx, game->img_co);
	if (game->img_ex)
		mlx_destroy_image(game->mlx, game->img_ex);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_array(game->map);
	ft_printf("Game closed.\n");
	exit(0);
	return (0);
}
