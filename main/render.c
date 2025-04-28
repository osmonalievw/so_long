/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:04:58 by raosmona          #+#    #+#             */
/*   Updated: 2025/04/25 16:52:17 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*select_texture(t_game *game, char c)
{
	if (c == '1')
		return (game->img.wall);
	else if (c == '0')
		return (game->img.floor);
	else if (c == 'C')
		return (game->img.collectible);
	else if (c == 'P')
		return (game->img.player);
	else if (c == 'E')
	{
		if (game->map.num_collectible == 0)
			return (game->img.exit_open);
		else
			return (game->img.exit_closed);
	}
	ft_printf("Error\nInvalid texture character: %c\n", c);
	return (NULL);
}

void	put_image_to_window(t_game *game, size_t x, size_t y, char c)
{
	void	*texture;

	texture = select_texture(game, c);
	if (texture)
		mlx_put_image_to_window(game->mlx, game->mlx_win, texture, x
			* game->img.img_width, y * game->img.img_height);
	else
		ft_printf("Error\nNo texture selected for character %c\n", c);
}

void	render_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			put_image_to_window(game, x, y, game->map.map[y][x]);
			x++;
		}
		y++;
	}
	put_image_to_window(game, game->player.x, game->player.y, 'P');
}

t_bool	can_move(t_game *game, char next_position)
{
	if (next_position == '1')
		return (FALSE);
	game->move_count += 1;
	ft_printf("Move count: %u\n", (unsigned int)game->move_count);
	if (next_position == 'E' && game->map.num_collectible == 0)
	{
		ft_printf("Exit is now open. You win!\n");
		free_all(*game, game->map.map, game->map.height);
		exit(0);
	}
	return (TRUE);
}
