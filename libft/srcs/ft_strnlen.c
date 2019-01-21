/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:35:46 by mlacombe          #+#    #+#             */
/*   Updated: 2018/12/12 16:42:32 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *src, size_t n)
{
	const char	*ptr;

	ptr = ft_memchr(src, 0, n);
	return (ptr ? ptr - src : n);
}
