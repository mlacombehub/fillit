/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:30:18 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 19:22:45 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	l;
	char	*ptr;

	l = ft_strnlen(s, n);
	if (!(ptr = ft_strnew(n)))
		return (NULL);
	ft_memcpy(ptr, s, l);
	ptr[l] = 0;
	return (ptr);
}
