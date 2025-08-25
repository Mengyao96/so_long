/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:32:25 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/25 16:57:20 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_game *gm)
{
	int		r;
	int		c;

	mlx_clear_window(gm->mlx, gm->win);
	r = 0;
	while (r < array_counts(gm->map))
	{
		c = 0;
		while (c < (int)ft_strlen(gm->map[0]))
		{
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img_bg, c * 32, r * 32);
			c++;
		}
		r++;
	}
}

void	moves_win_update(t_game *gm)
{
	char	*move_str;

	move_str = ft_itoa(gm->moves);
	mlx_string_put(gm->mlx, gm->win, 10, 10, 0xFFFFFF, "Total Moves: ");
	mlx_string_put(gm->mlx, gm->win, 120, 10, 0xFFFFFF, move_str);
	free(move_str);
}

void    render_game(t_game *gm)
{
	int		r;
	int		c;
	
	render_background(gm);
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
			else if (gm->map[r][c] == 'C')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img_co, c * 32, r * 32);
			else if (gm->map[r][c] == 'E')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img_ex, c * 32, r * 32);
			c++;
		}
		r++;
	}
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img_pl, gm->player.x * 32, gm->player.y * 32);
	moves_win_update(gm);
}


// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close_game, &vars);
// 	mlx_loop(vars.mlx);
// }

