/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:44:12 by raosmona          #+#    #+#             */
/*   Updated: 2025/04/28 15:14:33 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define IS_FILLED "X1"
# define CHAR_FILL "CE"

# define IMAGE_SIZE 64

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}				t_bool;

enum			e_components
{
	WALL,
	FLOOR,
	PLAYER,
	EXIT,
	EXIT_CLOSED,
	COLLECTIBLE
};

typedef struct s_map
{
	char		**map;
	char		**fill;
	size_t		width;
	size_t		height;
	size_t		num_collectible;
	size_t		num_exit;
	size_t		num_s_position;
}				t_map;

typedef struct s_img
{
	void		*img;
	void		*wall;
	void		*floor;
	void		*collectible;
	void		*player;
	void		*exit_open;
	void		*exit_closed;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_player
{
	size_t		x;
	size_t		y;
}				t_player;

typedef struct s_game
{
	t_map		map;
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_player	player;
	char		under_player;
	size_t		move_count;
	t_player	exit_pos;

}				t_game;

/* Program Entry and Resource Management */
void			free_all(t_game game, char **map, size_t i);
void			load_textures(t_game *game);
void			free_textures(t_game *game);
int				open_if_file_is_valid(char *av1);
void			error_exit(char *message);

/* Map Loading and Validation */
char			*get_next_line(int fd);
void			so_long(int fd, t_game *game);
void			move_list_to_double_pointer(t_game *game, t_list *map);
void			init_player_position(t_game *game);
void			init_exit_position(t_game *game);

/* Error Handling */
void			error_exit_with_lstclear(t_list *map, char *message);

/* Linked List Management */
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));

/* Input Handling and Game Logic */
int				ft_input(int key, void *game_);
t_bool			can_move(t_game *game, char next_position);

/* Window and Event Management */
int				close_window(t_game *game);

/* Rendering and Graphics */
void			render_map(t_game *game);
void			*select_texture(t_game *game, char c);
void			put_image_to_window(t_game *game, size_t x, size_t y, char c);
void			check_flood_fill(t_game *g);
void			ft_free_map_fill(char **map, size_t rows);
void			ft_error_and_free_fill(char *msg, t_game *game);

#endif