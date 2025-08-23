/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:59:10 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/22 15:55:15 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx_mms/mlx.h"

// utility functions
int		array_counts(char **array);
void	free_array(char **array);
char	**ft_add_to_array(char **arr, char *str);



#endif
