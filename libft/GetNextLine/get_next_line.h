/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:46:49 by raosmona          #+#    #+#             */
/*   Updated: 2025/01/11 13:34:46 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	char			*buff;
	struct s_list	*next;

}					t_list;

char				*get_next_line(int fd);
int					for_found_newline(t_list *list);
t_list				*for_find_last_node(t_list *list);
char				*for_get_line(t_list *list);
void				for_copy_str(t_list *list, char *str);
int					len_to_newline(t_list *list);
void				for_remake_list(t_list **list);
void				for_freemem(t_list **list, t_list *clean_node, char *buf);
void				for_create_list(t_list **list, int fd);

#endif