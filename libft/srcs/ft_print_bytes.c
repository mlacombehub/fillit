/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:41:43 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/21 19:48:14 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** prints the bytes from memory reversed
** we print from the [ptr] address, [size] bytes grouping by [step]
** prefixing with grouping number
** if step is 0 we juste print separated by space
*/

void	ft_print_bytes(void *ptr, int size, int step)
{
	unsigned char	*p;
	int				i;

	p = ptr;
	if (ptr)
	{
		i = 0;
		while (i < size)
		{
			if (step != 0 && i % step == 0)
			{
				ft_putnbr(i / step);
				ft_putstr("\t");
			}
			ft_print_bits(ft_reversed_bits(p[i]));
			ft_putstr(" ");
			i++;
			if (step != 0 && i % step == 0)
				ft_putstr("\n");
		}
	}
	ft_putstr("\n");
}
