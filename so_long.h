/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:59:10 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/26 21:09:09 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		mp_wd;
	int		mp_ht;

	t_pos	player;
	int		moves;

	int		collected;
	int		collectibles;
	int		exit_found;

	void	*img_bg;
	void	*img_fl;
	void	*img_wa;
	void	*img_pl;
	void	*img_co;
	void	*img_ex;

}			t_game;

// map parsing and checking
char		**parse_map(char *map_name);
int			map_check(t_game *game);

// map_utility functions
int			array_counts(char **array);
void		free_array(char **array);
char		**ft_add_to_array(char **arr, char *str);
void		get_elements(t_game *game);

// windows functions
int			launch_win(t_game *game);
int			get_map_height(char **map);
int			get_map_width(char **map);
int			close_game(t_game *game);

// images
int			load_images(t_game *game);

// render
void		render_game(t_game *gm);
void		put_image_to_window(t_game *gm, void *img, int x, int y);

// events and hooks
int			handle_keypress(int keycode, t_game *gm);
int			move_player(int keycode, t_game *gm);
void		moves_win_update(t_game *gm);

#endif
