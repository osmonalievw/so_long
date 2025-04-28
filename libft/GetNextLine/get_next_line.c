/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:44:16 by raosmona          #+#    #+#             */
/*   Updated: 2025/01/11 13:34:35 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	for_remake_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buff == NULL || clean_node == NULL)
		return ;
	last_node = for_find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->buff[i] && last_node->buff[i] != '\n')
		++i;
	while (last_node->buff[i] && last_node->buff[++i])
		buff[j++] = last_node->buff[i];
	buff[j] = '\0';
	clean_node->buff = buff;
	clean_node->next = NULL;
	for_freemem(list, clean_node, buff);
}

char	*for_get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	for_copy_str(list, next_str);
	return (next_str);
}

void	add(t_list **list, char *buff)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = for_find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->buff = buff;
	new_node->next = NULL;
}

void	for_create_list(t_list **list, int fd)
{
	int		readed;
	char	*buf;

	while (!for_found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		readed = read(fd, buf, BUFFER_SIZE);
		if (!readed)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	for_create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = for_get_line(list);
	for_remake_list(&list);
	return (next_line);
}
