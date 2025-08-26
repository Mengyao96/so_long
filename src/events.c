/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:16:42 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/26 21:52:32 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_game *gm)
{
	t_pos	move;

	ft_memset(&move, 0, sizeof(t_pos));
	if (keycode == 119)
		move.y = -1;
	else if (keycode == 97)
		move.x = -1;
	else if (keycode == 115)
		move.y = 1;
	else if (keycode == 100)
		move.x = 1;
	if (move.x == 0 && move.y == 0)
		return (0);
	if (gm->map[gm->player.y + move.y][gm->player.x + move.x] == '1')
		return (0);
	gm->moves += 1;
	if (gm->map[gm->player.y][gm->player.x] != 'E')
		gm->map[gm->player.y][gm->player.x] = '0';
	gm->player.x += move.x;
	gm->player.y += move.y;
	return (1);
}

void	check_collectible(t_game *gm)
{
	if (gm->map[gm->player.y][gm->player.x] == 'C')
	{
		gm->map[gm->player.y][gm->player.x] = '0';
		gm->collected += 1;
	}
}

void	check_exit(t_game *gm)
{
	if (gm->map[gm->player.y][gm->player.x] == 'E'
		&& gm->collected == gm->collectibles)
	{
		gm->exit_found = 1;
		printf("collected: %d\n", gm->collected);
		printf("total collectibles: %d\n", gm->collectibles);
		ft_printf("You win! Total moves: %d\n", gm->moves);
	}
}

int	handle_keypress(int keycode, t_game *gm)
{
	int	is_moved;

	if (keycode == 65307)
		close_game(gm);
	is_moved = move_player(keycode, gm);
	if (is_moved)
	{
		ft_printf("Moves: %d\n", gm->moves);
		check_collectible(gm);
		render_game(gm);
		check_exit(gm);
	}
	if (gm->exit_found == 1)
	{
		close_game(gm);
	}
	return (is_moved);
}
