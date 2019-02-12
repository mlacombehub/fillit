/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:39:57 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/08 13:04:00 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"

/*
** takes an int and print it out as square
*/

/*
** do a >> shift of squareside and set above squareside to 0
*/

/*
** bit masking to set the bigger bit above squareSide to 0
** complement by 0s if the number is missing left 0s
*/

void    ft_printmino(int mino, int sidesize)
{
    int newmino;
    int k;

    newmino = mino;
    k = 0;
    ft_putendl("this should print the tetrimino as represented by the bit with a side of square side");
    while (newmino > 0)
    {
        k++;
        if (k != 0 && k % (sidesize + 1) == 0)
        {
            ft_putchar('\n');
        }
        else
        {
            ft_putendl_nbr(newmino&1);
            newmino = newmino >> 1;
        }
    }
}
