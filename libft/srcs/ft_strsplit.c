/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:06:40 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 17:55:55 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char c)
{
	int	cnt;
	int	in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s)
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static size_t	ft_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	nb_word;
	size_t	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	nb_word = ft_word_count(s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nb_word + 1))) || !s)
	{
		free(tab);
		return (NULL);
	}
	while (nb_word--)
	{
		while (*s == c && *s)
			s++;
		if (!(tab[i] = ft_strsub(s, 0, ft_word_len(s, c))))
			ft_free_return(tab[i]);
		s = s + ft_word_len(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
