/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:59:10 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/24 22:12:14 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx_linux/mlx.h"

typedef struct s_game{
    void    *mlx;
    void    *win;

    char    **map;
    int     mp_wd;
	int     mp_ht;
	
	int		player_x; //column
	int		player_y; //row
	int		moves;

	int		collectibles_collected; //only one collectible for now, so yes or no is enough
	int		exit_found; //exit is closed until all collectibles are collected

	void	*img_fl; //0
	void	*img_wa; //1
	void	*img_pl; //P
	void	*img_co; //C
	void	*img_ex; //E

}	   t_game;




typedef struct	s_vars {
	void	*mlx;
	void	*win;
}		t_vars;



// utility functions
int		array_counts(char **array);
void	free_array(char **array);
char	**ft_add_to_array(char **arr, char *str);


// windows functions
int		get_map_height(char **map);
int		get_map_width(char **map);
int		close_win(int keycode, t_vars *vars);

// map functions
char	**parse_map(char *map_name);
int		map_check(char **map);

// images
int	load_images(t_game *game);

// render
void    render_map(t_game *gm);

#endif
