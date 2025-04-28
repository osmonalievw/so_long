/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:03:16 by raosmona          #+#    #+#             */
/*   Updated: 2024/12/22 18:32:37 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_format(int format, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += for_digit(va_arg(ap, int), 10);
	else if (format == 's')
		count += for_string(ap);
	else if (format == 'u')
		count += for_digit((unsigned int)va_arg(ap, int), 10);
	else if (format == 'x' || format == 'X')
		count += for_hex(format, ap);
	else if (format == 'p')
		count += for_ptr(ap);
	else if (format == 'c')
		count += for_char((char)va_arg(ap, int));
	else if (format == '%')
		count += for_char('%');
	return (count);
}

int	ft_printf(const char *instructions, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, instructions);
	while (instructions[i])
	{
		if (instructions[i] == '%')
		{
			i++;
			count += find_format(instructions[i], ap);
		}
		else
			count += write(1, &instructions[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
