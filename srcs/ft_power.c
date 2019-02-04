/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:39:44 by xbarthe           #+#    #+#             */
/*   Updated: 2019/01/25 17:41:36 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

uint16_t		ft_power(uint16_t nb, int power)
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
