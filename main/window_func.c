/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:34:10 by raosmona          #+#    #+#             */
/*   Updated: 2025/04/23 20:39:05 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_update(t_game *game, t_player *old_pos)
{
	put_image_to_window(game, old_pos->x, old_pos->y, game->under_player);
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->map.num_collectible--;
		game->map.map[game->player.y][game->player.x] = '0';
		if (game->map.num_collectible == 0)
		{
			ft_printf("All collectibles gathered! Exit is now open.\n");
			put_image_to_window(game, game->exit_pos.x, game->exit_pos.y, 'E');
		}
	}
	game->under_player = game->map.map[game->player.y][game->player.x];
	put_image_to_window(game, game->player.x, game->player.y, 'P');
	return (0);
}

static void	set_player_position(t_game *game, size_t x, size_t y)
{
	game->player.x = x;
	game->player.y = y;
}

int	ft_input(int key, void *game_)
{
	t_game		*game;
	t_player	old_pos;

	game = (t_game *)game_;
	old_pos.x = game->player.x;
	old_pos.y = game->player.y;
	if (key == ESC)
		mlx_loop_end(game->mlx);
	if (key == W)
		game->player.y -= 1;
	else if (key == S)
		game->player.y += 1;
	else if (key == A)
		game->player.x -= 1;
	else if (key == D)
		game->player.x += 1;
	else
		return (0);
	if (can_move(game, game->map.map[game->player.y][game->player.x]))
		ft_update(game, &old_pos);
	else
		set_player_position(game, old_pos.x, old_pos.y);
	return (0);
}

int	close_window(t_game *game)
{
	free_all(*game, game->map.map, game->map.height);
	exit(0);
	return (0);
}
