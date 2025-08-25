/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:16:42 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/25 17:02:31 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//-1 unidentified, 0 hit wall no move, 1 moved
// ESC key, W 119 A 97 S 115 D 100 keys
//0 no move, 1 move



int	move_player(int keycode, t_game *gm) 
{
	t_pos move;

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
	if (gm->map[gm->player.y][gm->player.x] == 'E' && gm->collected == gm->collectable)
	{
		gm->exit_found = 1;
		ft_printf("You win! Total moves: %d\n", gm->moves);
	}
}



int	handle_keypress(int keycode, t_game *gm) 
{
	int	is_moved;

	if (keycode == 65307) 
		close_game(gm);
	is_moved = move_player(keycode, gm);
	printf("Moves: %d\n", gm->moves);
	
	if (is_moved)
	{
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
