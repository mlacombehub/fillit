/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:39:57 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/21 19:59:08 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/fillit.h"

/*
 ** takes an int and print it out as square
 ** do a >> shift of squareside and set above squareside to 0
 ** bit masking to set the bigger bit above squareSide to 0
 ** complement by 0s if the number is missing left 0s
 */

void	ft_printmino(int mino, int sidesize)
{
	int newmino;
	int k;

	newmino = mino;
	k = 0;
	while (newmino > 0)
	{
		k++;
		if (k != 0 && k % (sidesize + 1) == 0)
		{
		}
		else
		{
			newmino = newmino >> 1;
		}
	}
}
