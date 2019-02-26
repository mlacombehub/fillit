/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:50:05 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 19:22:13 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	n;

	n = 0;
	while (n < len && (src[n] != 0))
	{
		dst[n] = src[n];
		n++;
	}
	while (n < len)
		dst[n++] = 0;
	return (dst);
}
