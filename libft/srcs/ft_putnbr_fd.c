/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:39:35 by mlacombe          #+#    #+#             */
/*   Updated: 2018/11/28 13:39:00 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long nbx;

	nbx = n;
	if (nbx < 0)
	{
		ft_putchar_fd('-', fd);
		nbx = -nbx;
	}
	if (nbx > 9)
		ft_putnbr_fd(nbx / 10, fd);
	ft_putchar_fd((nbx % 10) + '0', fd);
}
