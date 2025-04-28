/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:17:32 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/24 17:17:45 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	const unsigned char	*p;

	p = (const unsigned char *)str;
	while (n > 0)
	{
		if (*p == (unsigned char)ch)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
