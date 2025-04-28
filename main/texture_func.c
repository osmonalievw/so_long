/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:06:40 by raosmona          #+#    #+#             */
/*   Updated: 2025/04/23 19:42:17 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	*load_texture(void *mlx, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

static void	handle_texture_error(t_game *game)
{
	ft_printf("Error\nFailed to load textures\n");
	free_textures(game);
	ft_free_map_fill(game->map.map, game->map.height);
	game->map.map = NULL;
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(1);
}

void	load_textures(t_game *game)
{
	game->img.wall = load_texture(game->mlx, "assets/1_wall.xpm",
			&game->img.img_width, &game->img.img_height);
	game->img.floor = load_texture(game->mlx, "assets/0_floor.xpm",
			&game->img.img_width, &game->img.img_height);
	game->img.collectible = load_texture(game->mlx, "assets/C_item.xpm",
			&game->img.img_width, &game->img.img_height);
	game->img.player = load_texture(game->mlx, "assets/P_hero.xpm",
			&game->img.img_width, &game->img.img_height);
	game->img.exit_open = load_texture(game->mlx, "assets/E_exit_open.xpm",
			&game->img.img_width, &game->img.img_height);
	game->img.exit_closed = load_texture(game->mlx, "assets/E_exit_closed.xpm",
			&game->img.img_width, &game->img.img_height);
	if (!game->img.wall || !game->img.floor || !game->img.collectible
		|| !game->img.player || !game->img.exit_open || !game->img.exit_closed)
		handle_texture_error(game);
}

static void	destroy_image_if_exists(void *mlx, void **image)
{
	if (*image)
	{
		mlx_destroy_image(mlx, *image);
		*image = NULL;
	}
}

void	free_textures(t_game *game)
{
	destroy_image_if_exists(game->mlx, &game->img.wall);
	destroy_image_if_exists(game->mlx, &game->img.floor);
	destroy_image_if_exists(game->mlx, &game->img.collectible);
	destroy_image_if_exists(game->mlx, &game->img.player);
	destroy_image_if_exists(game->mlx, &game->img.exit_open);
	destroy_image_if_exists(game->mlx, &game->img.exit_closed);
}
