/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:53:13 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/22 15:53:17 by mezhang          ###   ########.fr       */
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

void	free_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
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
