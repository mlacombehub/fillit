/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:12:01 by mlacombe          #+#    #+#             */
/*   Updated: 2018/12/14 13:54:11 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	i = 0;
	if (!(c = (char *)malloc(sizeof(*c) * (len + 1))) || !s)
		return (NULL);
	while (i < len)
	{
		c[i] = s[i + start];
		i++;
	}
	c[i] = '\0';
	return (c);
}
