/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:54:26 by xbarthe           #+#    #+#             */
/*   Updated: 2019/01/24 18:20:55 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"

/*
** takes an int and print it out as square
*/

void    ft_printmino(int mino, int sidesize)
{
    int newmino;
    int k;

    newmino = mino;
    k = 0;
    ft_putendl("this should print the tetrimino as represented by the bit with a side of square side");
    // do a >> shift of squareside and set above squareside to 0
    while (newmino > 0)
    {
        // bit masking to set the bigger bit above squareSide to 0
        // complement by 0s if the number is missing left 0s
        if (k % (sidesize - 1) == 0)
            ft_putchar('\n');
        else 
        {
            ft_putnbr(newmino&1); 
            newmino = newmino >> 1;
        }   
        k++;
    }
}