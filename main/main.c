/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:10:06 by raosmona          #+#    #+#             */
/*   Updated: 2025/04/23 20:42:36 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all(t_game game, char **map, size_t i)
{
	while (i > 0)
		free(map[--i]);
	free(map);
	free_textures(&game);
	mlx_clear_window(game.mlx, game.mlx_win);
	mlx_destroy_window(game.mlx, game.mlx_win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}

void	error_exit(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(1);
}

int	open_if_file_is_valid(char *av1)
{
	int		fd;
	size_t	av1_len;

	av1_len = ft_strlen(av1);
	if (av1_len < 4 || ft_strncmp(av1 + av1_len - 4, ".ber", 5))
		error_exit("file is not .ber");
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		error_exit("file crashed");
	return (fd);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
		error_exit("need ./so_long <map.ber>");
	fd = open_if_file_is_valid(av[1]);
	game = (t_game){0};
	so_long(fd, &game);
	close(fd);
	check_flood_fill(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		error_exit(strerror(errno));
	load_textures(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.map.width * IMAGE_SIZE,
			game.map.height * IMAGE_SIZE, av[0]);
	if (game.mlx_win == NULL)
		error_exit(strerror(errno));
	render_map(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, ft_input, &game);
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	free_all(game, game.map.map, game.map.height);
	exit(0);
}
