/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:06:45 by raosmona          #+#    #+#             */
/*   Updated: 2025/04/04 18:34:51 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_ptr_digit(unsigned long nb, int base)
{
	int		count;
	char	*base_ch;

	base_ch = "0123456789abcdef";
	if (nb < (unsigned long)base)
		return (write(1, &base_ch[nb], 1));
	else
	{
		count = for_ptr_digit(nb / base, base);
		return (count + for_ptr_digit(nb % base, base));
	}
}

int	for_ptr(va_list ap)
{
	unsigned long	ptr;
	int				count;

	count = 0;
	ptr = (unsigned long)va_arg(ap, void *);
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	ft_putstr_fd("0x", 1);
	count += for_ptr_digit(ptr, 16);
	return (2 + count);
}
