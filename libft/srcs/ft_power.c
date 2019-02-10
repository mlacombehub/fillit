/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:13:19 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/10 19:15:50 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
