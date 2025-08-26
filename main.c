/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:58:25 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/26 21:39:27 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	*map_name;

	if (argc != 2)
		return (ft_printf("Error\nLack Of Map File.\n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	map_name = ft_strjoin("maps/", argv[1]);
	game.map = parse_map(map_name);
	free(map_name);
	if (game.map == NULL)
		return (1);
	if (map_check(&game) < 0)
		return (close_game(&game), 1);
	if (launch_win(&game) < 0)
		return (close_game(&game), 1);
	if (load_images(&game) < 0)
		return (close_game(&game), 1);
	render_game(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

// void	leaks(void)
// {
// 	system("leaks a.out");
// }

// int	main(int argc, char **argv)
// {
// 	t_game	game;
// 	char	*map_name;

// 	atexit(leaks);
// 	if (argc != 2)
// 		return (ft_printf("Error\nLack Of Map File.\n"), 1);
// 	ft_memset(&game, 0, sizeof(t_game));
// 	map_name = ft_strjoin("maps/", argv[1]);
// 	game.map = parse_map(map_name);
// 	free(map_name);
// 	if (game.map == NULL)
// 		return (1);
// 	if (map_check(&game) < 0)
// 		return (free(game.map), 1);
// 	if (launch_win(&game) < 0)
// 		return (free(game.map), 1);
// 	if (load_images(&game) < 0)
// 		return (free(game.map), free(game.mlx), free(game.win), 1);
// 	render_game(&game);
// 	mlx_key_hook(game.win, handle_keypress, &game);
// 	mlx_hook(game.win, 17, 0, close_game, &game);
// 	mlx_loop(game.mlx);
// 	return (0);
// }
