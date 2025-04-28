/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:53:55 by raosmona          #+#    #+#             */
/*   Updated: 2025/04/23 20:09:56 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	copy_map_to_fill(t_game *game)
{
	size_t	y;

	y = 0;
	game->map.fill = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.fill)
		ft_error_and_free_fill("Failed to allocate map fill.", game);
	while (y < game->map.height)
	{
		game->map.fill[y] = ft_strdup(game->map.map[y]);
		if (!game->map.fill[y])
		{
			while (y > 0)
				free(game->map.fill[--y]);
			free(game->map.fill);
			ft_error_and_free_fill("Failed to copy map to fill.", game);
		}
		y++;
	}
	game->map.fill[y] = NULL;
}

static void	flood_fill(t_game *g, int x, int y, char r)
{
	if (x < 0 || y < 0 || x >= (int)g->map.width || y >= (int)g->map.height)
		return ;
	if (strchr(IS_FILLED, g->map.fill[y][x]))
		return ;
	g->map.fill[y][x] = r;
	flood_fill(g, x + 1, y, r);
	flood_fill(g, x - 1, y, r);
	flood_fill(g, x, y + 1, r);
	flood_fill(g, x, y - 1, r);
}

static void	check_remaining_targets(t_game *g)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (strchr(CHAR_FILL, g->map.fill[y][x]))
				ft_error_and_free_fill("Unreachable collectible or exit found.",
					g);
			x++;
		}
		y++;
	}
}

void	check_flood_fill(t_game *g)
{
	copy_map_to_fill(g);
	flood_fill(g, g->player.x, g->player.y, 'X');
	check_remaining_targets(g);
	ft_free_map_fill(g->map.fill, g->map.height);
	g->map.fill = NULL;
}
