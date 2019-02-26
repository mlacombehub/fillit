/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_nbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:24:33 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 19:01:29 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_nbr_fd(int nbr, int fd)
{
	if (fd >= 0)
	{
		ft_putnbr_fd(nbr, fd);
		ft_putchar_fd('\n', fd);
	}
}
