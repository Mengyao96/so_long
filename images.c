/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:51:37 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/24 22:01:34 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_game *game)
{
	int	img_wd;
	int	img_ht;

	game->img_fl = mlx_xpm_file_to_image(game->mlx, "src_tileset/0.xpm", 
		&img_wd, &img_ht);
	game->img_wa = mlx_xpm_file_to_image(game->mlx, "src_tileset/1.xpm", 
		&img_wd, &img_ht);
	game->img_pl = mlx_xpm_file_to_image(game->mlx, "src_tileset/P.xpm", 
		&img_wd, &img_ht);
	game->img_co = mlx_xpm_file_to_image(game->mlx, "src_tileset/C.xpm", 
		&img_wd, &img_ht);
	game->img_ex = mlx_xpm_file_to_image(game->mlx, "src_tileset/E.xpm", 
		&img_wd, &img_ht);
	if (!game->img_fl || !game->img_wa || !game->img_pl || 
		!game->img_co || !game->img_ex)
		return (-1);
	return (1);
}


//https://www.online-image-editor.com/
//https://convertio.co/png-xpm/
//https://itch.io/game-assets/free/tag-top-down