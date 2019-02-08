/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:01:09 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/08 18:01:26 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/includes/libft.h"

/*
** calculates 'nb' to the power 'power'
*/

uint16_t	ft_power(uint16_t nb, int power)
{
	int	i;
	int	result;

	i = 1;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power == 0)
		return (1);
	while (i++ < power)
		result = result * nb;
	return (result);
}
