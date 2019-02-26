/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:28:30 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 18:37:47 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*dst;
	size_t	i;
	size_t	count;
	long	tmp_n;

	tmp_n = (long)n;
	i = 0;
	count = ft_nlen(n);
	if (tmp_n < 0 || count == 0)
		count++;
	if (!(dst = ft_strnew(count)))
		return (FALSE);
	if (tmp_n < 0)
	{
		tmp_n = -tmp_n;
		dst[0] = '-';
		i++;
	}
	while (count-- > i)
	{
		dst[count] = (tmp_n % 10) + '0';
		tmp_n /= 10;
	}
	return (dst);
}
