/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:28:32 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 18:58:18 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *psrc;
	unsigned char *pdst;

	psrc = (unsigned char*)src;
	pdst = (unsigned char*)dst;
	while ((int)--len >= 0)
	{
		if (psrc < pdst)
			*(pdst + len) = *(psrc + len);
		else
			*(pdst++) = *(psrc++);
	}
	return (dst);
}
