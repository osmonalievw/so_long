/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:18:27 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/24 17:18:31 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *diff1, const void *diff2, size_t n)
{
	const unsigned char	*d1;
	const unsigned char	*d2;

	d1 = diff1;
	d2 = diff2;
	while (n > 0)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		d1++;
		d2++;
		n--;
	}
	return (0);
}
