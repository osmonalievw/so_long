/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:06:31 by raosmona          #+#    #+#             */
/*   Updated: 2024/12/23 15:35:28 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_string(va_list ap)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str != '\0')
	{
		for_char((int)*str);
		len++;
		str++;
	}
	return (len);
}
