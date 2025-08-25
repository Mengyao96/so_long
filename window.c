/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:42:24 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/25 14:20:13 by mezhang          ###   ########.fr       */
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


// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
	
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Galaxy_23");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
	
// 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 				// &img.endian);
// 	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }
