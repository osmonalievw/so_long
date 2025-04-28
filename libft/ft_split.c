/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:23:14 by raosmona          #+#    #+#             */
/*   Updated: 2024/11/24 18:04:51 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_list(char const *s, char c, int *i)
{
	int	l1;
	int	l2;

	while (s[*i] == c)
		(*i)++;
	l1 = *i;
	while (s[*i] != '\0' && s[*i] != c)
		(*i)++;
	l2 = *i;
	return (ft_substr(s, l1, l2 - l1));
}

static int	count_words(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			n++;
			while (*s && *s != c)
				s++;
		}
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	if (!s)
		return (NULL);
	str = malloc((sizeof(char *)) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		str[j] = make_list(s, c, &i);
		if (!str[j])
		{
			while (j--)
				free(str[j]);
			free(str);
			return (NULL);
		}
		j++;
	}
	str[j] = NULL;
	return (str);
}
