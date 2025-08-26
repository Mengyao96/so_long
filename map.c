/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:20:30 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/26 11:47:10 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(char *map_name)
{
	int		fd;
	char	**map;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), NULL);
	line = ft_strtrim(get_next_line(fd), "\n");
	map = NULL;
	while (1)
	{
		if (line == NULL)
			break ;
		map = ft_add_to_array(map, line);
		if (map == NULL)
			return (free_array(map), free(line), perror("Error\n"), NULL);
		free(line);
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	close(fd);
	return (map);
}

static int	check_wall(char **map, int r)
{
	int	i;

	if (r < 3)
		return (ft_printf("Error\nMap Is Too Small."), -1);
	while (--r >= 0)
	{
		if (r == array_counts(map) - 1 || r == 0)
		{
			i = 0;
			while (map[r][i] == '1')
				i++;
			if (i != (int)ft_strlen(map[0]))
				return (ft_printf("Error\nNot A Rectangular."), -1);
		}
		else
		{
			if (map[r][0] != '1' || map[r][ft_strlen(map[r]) - 1] != '1'
				|| ft_strlen(map[r]) != ft_strlen(map[0]))
				return (ft_printf("Error\nNot Closed / Not Rectangular."), -1);
		}
	}
	return (1);
}

static int	check_elements(t_game *game, int r)
{
	int	i;
	int	cep[3];

	cep[0] = 0;
	cep[1] = 0;
	cep[2] = 0;
	while (--r >= 0)
	{
		i = 0;
		while (game->map[r][i])
		{
			if (game->map[r][i] == 'C')
				cep[0]++;
			else if (game->map[r][i] == 'E')
				cep[1]++;
			else if (game->map[r][i] == 'P')
				cep[2]++;
			else if (game->map[r][i] != '0' && game->map[r][i] != '1')
				return (ft_printf("Error\nInvalid Character In Map"), -1);
			i++;
		}
	}
	if (cep[0] < 1 || cep[1] != 1 || cep[2] != 1)
		return (ft_printf("Error\nInvalid Map"), -1);
	return (1);
}

void	get_elements(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	while (game->map[r])
	{
		c = 0;
		while (game->map[r][c])
		{
			if (game->map[r][c] == 'C')
				game->collectable++;
			if (game->map[r][c] == 'P')
			{
				game->player.x = c;
				game->player.y = r;
			}
			c++;
		}
		r++;
	}
}

int	map_check(t_game *game)
{
	int	row;

	row = array_counts(game->map);
	if (check_wall(game->map, row) < 0 || check_elements(game, row) < 0)
		return (-1);
	else
		get_elements(game);
	return (0);
}

/* void	leaks(void)
{
	system("leaks -q map");
}


int	main(void)
{
	char	**map;

	atexit(leaks);
	map = parse_map();
	if (map == NULL)
		return (1);
	if (check_wall(map) < 0)
		return (free(map), 1);
	else
	{
		printf("Map is valid.\n");
		int i = 0;
		while (map[i])
		{
			printf("%s\n", map[i]);
			free(map[i]);
			i++;
		}
		free(map);
	}
	return (0);

} */
