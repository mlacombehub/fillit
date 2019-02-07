/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:22:38 by mlacombe          #+#    #+#             */
/*   Updated: 2019/01/25 17:48:07 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_sizeofmap(int ret)
{
	size_t	i;
	int		min;

	i = 0;
	min = ret * 4;
	
	while (i++)
		if (i * i >= min)
			break;
	return (i);
}

void	ft_solver()
{
	long	map;
	t_piece	piece;
	int		size_map;

	size_map = ft_sizeofmap(map);
	
}