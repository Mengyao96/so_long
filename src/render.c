/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:32:25 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/26 17:36:06 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves_win_update(t_game *gm)
{
	char	*move_str;

	move_str = ft_itoa(gm->moves);
	mlx_string_put(gm->mlx, gm->win, 10, 10, 0xFFFFFF, "Total Moves: ");
	mlx_string_put(gm->mlx, gm->win, 120, 10, 0xFFFFFF, move_str);
	free(move_str);
}

void	put_image_to_window(t_game *gm, void *img, int x, int y)
{
	mlx_put_image_to_window(gm->mlx, gm->win, img, x * 32, y * 32);
}

void	render_game(t_game *gm)
{
	int	r;
	int	c;

	r = 0;
	while (r < array_counts(gm->map))
	{
		c = 0;
		while (c < (int)ft_strlen(gm->map[0]))
		{
			if (gm->map[r][c] == '0')
				put_image_to_window(gm, gm->img_fl, c, r);
			else if (gm->map[r][c] == '1')
				put_image_to_window(gm, gm->img_wa, c, r);
			else if (gm->map[r][c] == 'C')
				put_image_to_window(gm, gm->img_co, c, r);
			else if (gm->map[r][c] == 'E')
				put_image_to_window(gm, gm->img_ex, c, r);
			c++;
		}
		r++;
	}
	put_image_to_window(gm, gm->img_pl, gm->player.x, gm->player.y);
	moves_win_update(gm);
}
