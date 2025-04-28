/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:07:06 by raosmona          #+#    #+#             */
/*   Updated: 2024/12/22 16:59:37 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_digit(long nb, int base)
{
	int		count;
	char	*base_ch;

	base_ch = "0123456789abcdef";
	if (nb < 0)
	{
		write(1, "-", 1);
		return (for_digit(-nb, base) + 1);
	}
	else if (nb < base)
		return (write(1, &base_ch[nb], 1));
	else
	{
		count = for_digit(nb / base, base);
		return (count + for_digit(nb % base, base));
	}
}

int	for_digit_upcase(long nb, int base)
{
	int		count;
	char	*base_ch;

	base_ch = "0123456789ABCDEF";
	if (nb < 0)
	{
		write(1, "-", 1);
		return (for_digit_upcase(-nb, base) + 1);
	}
	else if (nb < base)
		return (write(1, &base_ch[nb], 1));
	else
	{
		count = for_digit_upcase(nb / base, base);
		return (count + for_digit_upcase(nb % base, base));
	}
}
