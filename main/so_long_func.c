/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:39:16 by raosmona          #+#    #+#             */
/*   Updated: 2025/04/23 19:48:41 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit_with_lstclear(t_list *map, char *message)
{
	ft_printf("Error\n%s\n", message);
	ft_lstclear(&map, free);
	exit(1);
}

void	move_list_to_double_pointer(t_game *game, t_list *map)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	game->map.map = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
	if (game->map.map == NULL)
		error_exit_with_lstclear(map, "failed malloc");
	tmp = map;
	while (i < game->map.height)
	{
		game->map.map[i] = tmp->buff;
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&map, NULL);
}

void	init_exit_position(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'E')
			{
				game->exit_pos.x = x;
				game->exit_pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_player_position(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				game->under_player = '0';
				game->map.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
