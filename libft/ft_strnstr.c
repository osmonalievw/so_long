/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:29:33 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/24 17:29:40 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	find_i;

	i = 0;
	find_i = ft_strlen(to_find);
	if (!*to_find)
		return ((char *)str);
	while (i + find_i <= n && str[i] != '\0')
	{
		if (ft_strncmp(&str[i], to_find, find_i) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
