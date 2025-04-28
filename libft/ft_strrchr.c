/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:29:54 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/24 17:30:02 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	const char	*last_i;

	last_i = NULL;
	while (*str)
	{
		if (*str == (char)to_find)
			last_i = str;
		str++;
	}
	if (to_find == '\0')
		return ((char *)str);
	return ((char *)last_i);
}
