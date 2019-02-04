/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:19:25 by xbarthe           #+#    #+#             */
/*   Updated: 2019/01/25 17:33:18 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_power
*/

int		ft_power(int nb, int power)
{
	int i;
	int result;

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
