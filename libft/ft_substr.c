/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:31:50 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/24 17:31:52 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*data_size;
	size_t	length;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		return (ft_strdup(""));
	if (start + len > length)
		i = length - start;
	else
		i = len;
	data_size = malloc((sizeof(char) * i) + 1);
	if (!data_size)
		return (NULL);
	ft_strlcpy(((char *)data_size), (s + start), i + 1);
	return (data_size);
}
