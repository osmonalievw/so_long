/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:19:14 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/24 17:19:22 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*d;

	d = (unsigned char *)dest;
	if (!src && !dest)
		return (NULL);
	while (size-- > 0)
		*d++ = *(unsigned char *)src++;
	return (dest);
}
