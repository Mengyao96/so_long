/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:32:25 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/24 22:11:35 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void player_pos_update(t_game *gm, int new_x, int new_y)
{
	int	moves_x;
	int	moves_y;
	
	moves_x = new_x - gm->player_x;
	if (moves_x < 0)
		gm->moves = -moves_x;
	moves_y = new_y - gm->player_y;
	if (moves_y < 0)
		gm->moves += -moves_y;
	if (gm->moves == 0)
		return ;
	else
	{
		gm->player_x = new_x;
		gm->player_y = new_y;
		ft_printf("Moves: %d\n", gm->moves);
	}
}

void    render_map(t_game *gm)
{
	int		r;
	int		c;
	
	r = 0;
	while (r < array_counts(gm->map))
	{
		c = 0;
		while (c < (int)ft_strlen(gm->map[0]))
		{
			if (gm->map[r][c] == '0')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img_fl, c * 32, r * 32);
			else if (gm->map[r][c] == '1')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img_wa, c * 32, r * 32);
			else if (gm->map[r][c] == 'P')
			{
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img_pl, c * 32, r * 32);
				player_pos_update(gm, c, r);
			}
			else if (gm->map[r][c] == 'C')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img_co, c * 32, r * 32);
			else if (gm->map[r][c] == 'E')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img_ex, c * 32, r * 32);
			c++;
		}
		r++;
	}
}


// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
// 	mlx_loop(vars.mlx);
// }

