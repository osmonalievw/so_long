/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:24:07 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/24 17:24:11 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	while (*str)
	{
		if (*str == (char)to_find)
			return ((char *)str);
		str++;
	}
	if (to_find == '\0')
		return ((char *)str);
	return (NULL);
}
