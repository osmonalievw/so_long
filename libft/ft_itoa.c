/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:17:08 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/27 15:14:16 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_count(int n)
{
	int	digit;

	digit = !n;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	bool	sign;
	int		count;
	char	*result;

	sign = n < 0;
	count = size_count(n) + sign;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (sign)
	{
		*result = '-';
		n = -n;
	}
	while (count-- > sign)
	{
		result[count] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
