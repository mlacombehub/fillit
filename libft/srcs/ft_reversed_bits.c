/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversed_bits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:26:13 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 19:04:51 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_reversed_bits(unsigned char octet)
{
	int				i;
	unsigned char	last;
	unsigned char	reversed;

	i = 0;
	reversed = 0;
	while (i++ < 7)
	{
		last = octet & 1;
		octet >>= 1;
		reversed += last;
		reversed <<= 1;
	}
	return (reversed);
}
