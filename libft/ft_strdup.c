/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:24:59 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/24 17:25:03 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int			i;
	const char	*memo;

	i = ft_strlen(src);
	memo = malloc((sizeof(char) * i) + 1);
	if (!memo)
		return (NULL);
	ft_strlcpy((char *)memo, src, i + 1);
	return ((char *)memo);
}
