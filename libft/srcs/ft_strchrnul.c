/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:32:06 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 19:07:26 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchrnul(const char *s, int c)
{
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		else if (*s++ == '\0')
			return ((char *)s);
	}
	return (NULL);
}
