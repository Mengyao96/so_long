/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:20:30 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/29 19:29:29 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_trimmed_line(int fd)
{
	char	*tmp;
	char	*trimmed_line;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	trimmed_line = ft_strtrim(tmp, "\n");
	free(tmp);
	return (trimmed_line);
}

char	**parse_map(char *map_name)
{
	int		fd;
	char	**map;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nCannot Open Map.\n"), NULL);
	line = get_next_trimmed_line(fd);
	if (!line)
		return (close(fd), NULL);
	map = NULL;
	while (1)
	{
		if (line == NULL)
			break ;
		map = ft_add_to_array(map, line);
		if (map == NULL)
			return (free(line), close(fd), ft_printf("Error\nCannot \
				 Add Line To Map.\n"), NULL);
		free(line);
		line = get_next_trimmed_line(fd);
	}
	close(fd);
	return (map);
}

static int	check_wall(char **map, int r)
{
	int	i;

	if (r <= 3)
		return (ft_printf("Error\nMap Is Too Small.\n"), -1);
	while (--r >= 0)
	{
		if (r == array_counts(map) - 1 || r == 0)
		{
			i = 0;
			while (map[r][i] == '1')
				i++;
			if (ft_strlen(map[r]) != ft_strlen(map[0]))
				return (ft_printf("Error\nNot Rectangular.\n"), -1);
			if (i != (int)ft_strlen(map[0]))
				return (ft_printf("Error\nNot Closed.\n"), -1);
		}
		else
		{
			if (ft_strlen(map[r]) != ft_strlen(map[0]))
				return (ft_printf("Error\nNot Rectangular.\n"), -1);
			if (map[r][0] != '1' || map[r][ft_strlen(map[r]) - 1] != '1')
				return (ft_printf("Error\nNot Closed.\n"), -1);
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
				return (ft_printf("Error\nInvalid Character In Map.\n"), -1);
			i++;
		}
	}
	if (cep[0] < 1 || cep[1] != 1 || cep[2] != 1)
		return (ft_printf("Error\nInvalid Number Of Elements.\n"), -1);
	return (1);
}

int	map_check(t_game *game)
{
	int	row;

	row = array_counts(game->map);
	if (check_wall(game->map, row) < 0 || check_elements(game, row) < 0)
		return (-1);
	else
	{
		get_elements(game);
		ft_printf("Collectibles: %d\n", game->collectibles);
	}
	return (0);
}
