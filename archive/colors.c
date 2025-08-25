/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:58:12 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/24 12:55:00 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    add_shade(double dist, int color)
{
    int   	trgb[4];
	double	shade;

	if (dist < 0.0)
		dist = 0.0;
	if (dist > 1.0)
		dist = 1.0;
	shade = 1.0 - dist;
    trgb[0] = get_color_element(color, 't');
	trgb[1] = get_color_element(color, 'r') * shade;
	trgb[2] = get_color_element(color, 'g') * shade;
	trgb[3] = get_color_element(color, 'b') * shade;
	return (create_trgb(trgb[0], trgb[1], trgb[2], trgb[3]));
}

void	get_opposite(int *color)
{
	int   	trgb[4];

	trgb[0] = get_color_element(color, 't');
	trgb[1] = 255 - get_color_element(color, 'r');
	trgb[2] = 255 - get_color_element(color, 'g');
	trgb[3] = 255 - get_color_element(color, 'b');
}

/*
colors.c 文件（或任何你用来存放颜色函数的名称，比如 utils.c）应该包含用于生成、操作和转换颜
色的所有函数。例如，你之前问到的 create_trgb、add_shade 和 get_opposite 函数就应该放在这个
文件里。
*/

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 || g << 8 | b);
}

int get_color_element(int trgb, char c)
{
    if (c == 't')
        return ((trgb >> 24) & 0xFF);
    else if (c == 'r')
        return ((trgb >> 16) & 0xFF);
    else if (c == 'g')
        return ((trgb >> 8) & 0xFF);
    else if (c == 'b')
        return (trgb & 0xFF);
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
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 				&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }