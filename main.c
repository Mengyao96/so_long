/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:58:25 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/25 21:49:49 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	t_game	game;

	atexit(leaks);
	ft_memset(&game, 0, sizeof(t_game));
	game.map = parse_map("maps/map.ber");
	if (game.map == NULL)
		return (1);
	if (map_check(&game) < 0)
		return (free(game.map), 1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free(game.map), 1);
	game.mp_wd = get_map_width(game.map);
	game.mp_ht = get_map_height(game.map);
	game.win = mlx_new_window(game.mlx, game.mp_wd * 32, game.mp_ht * 32,
			"Galaxy_23");
	if (!game.win)
		return (free(game.map), free(game.mlx), 1);
	if (load_images(&game) < 0)
		return (free(game.map), free(game.mlx), free(game.win), 1);
	render_game(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
