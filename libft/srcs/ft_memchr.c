/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:42:44 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 18:56:29 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*u_s;
	size_t			i;

	u_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (u_s[i] == (unsigned char)c)
			return ((void *)u_s + i);
		i++;
	}
	return (NULL);
}
