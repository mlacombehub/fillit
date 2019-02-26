/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:35:41 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 19:10:33 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*ptr;

	l = ft_strlen(s);
	if (!(ptr = ft_strnew(l)))
		return (NULL);
	ft_memcpy(ptr, s, l);
	ptr[l] = 0;
	return (ptr);
}
