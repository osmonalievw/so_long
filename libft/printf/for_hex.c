/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:06:58 by raosmona          #+#    #+#             */
/*   Updated: 2024/12/18 18:59:16 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_hex(int ch, va_list ap)
{
	unsigned int	value;
	int				count;

	count = 0;
	value = va_arg(ap, unsigned int);
	if (ch == 'x')
		count += for_digit(value, 16);
	if (ch == 'X')
		count += for_digit_upcase(value, 16);
	return (count);
}
