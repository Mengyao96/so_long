/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:20:30 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/22 22:41:35 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	array_counts(char **array)
{
	int	counts;

	if (array == NULL)
		return (0);
	counts = 0;
	while (array[counts])
		counts++;
	return (counts);
}

char	**ft_add_to_array(char **arr, char *str)
{
	char	**new_arr;
	int		counts;
	int		i;

	counts = 0;
	if (arr)
		counts = array_counts(arr);
	new_arr = malloc(sizeof(char *) * (counts + 2));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < counts)
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (!new_arr[i])
			return (free_array(new_arr), NULL);
		i++;
	}
	new_arr[i] = ft_strdup(str);
	if (!new_arr[i])
		return (free_array(new_arr), NULL);
	new_arr[i + 1] = NULL;
	if (arr)
		free_array(arr);
	return (new_arr);
}

char	**parse_map(void)
{
	int		fd;
	char	**map;
	char	*line;

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (perror("Error opening map file"), NULL);
	line = ft_strtrim(get_next_line(fd), "\n");
	map = NULL;
	while (1)
	{
		if (line == NULL)
			break;
		map = ft_add_to_array(map, line);
		if (map == NULL)
			return (free_array(map), free(line), perror("Error malloc"), NULL);
		free(line);
		line = ft_strtrim(get_next_line(fd), "\n");

	}
	close(fd);
	return (map);
}

int	check_map(char **map)
{
	int	r;
	int	i;

	r = array_counts(map);
	if (r < 3)
		return (printf("Map is too small.\n"), -1);
	while (--r >= 0)
	{
		if (r == array_counts(map) - 1 || r == 0)
		{
			i = 0;
			while (map[r][i] == '1')
				i++;
			if (i != ft_strlen(map[r]))
				return (printf("Map is not closed.\n"), -1);
		}
		else
		{
			if (map[r][0] != '1' || map[r][ft_strlen(map[r]) - 1] != '1'
				|| ft_strlen(map[r]) != ft_strlen(map[0]))
				return (printf("Map is not closed or not rectangular.\n"), -1);
		}
	}
	return (1);
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
	if (check_map(map) < 0)
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
