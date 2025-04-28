/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:05:54 by raosmona          #+#    #+#             */
/*   Updated: 2025/04/23 20:09:59 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_general(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	ft_error_and_free_fill(char *msg, t_game *game)
{
	ft_printf("Error\n%s\n", msg);
	if (game->map.fill)
	{
		ft_free_map_fill(game->map.fill, game->map.height);
		game->map.fill = NULL;
	}
	if (game->map.map)
	{
		ft_free_map_fill(game->map.map, game->map.height);
		game->map.map = NULL;
	}
	exit(1);
}

void	ft_free_map_fill(char **map, size_t rows)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (i < rows && map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}
