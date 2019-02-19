/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:39:57 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/19 16:52:41 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

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

void    ft_printmap(t_piece *tab, int m_size, int p_qty)
{
    char    map[m_size * (m_size + 1)];
    int     k;

    k = m_size * (m_size + 1);
    map[k + 1] = '\0';
    while (--k >= 1)
    {
        if (k % (m_size + 1) == 0 && k != 0)
                map[k] = '\n';
        else
            map[k] = '.';
    }
    k--;
    ft_putendl("Map size :");//
    ft_putendl_nbr(m_size);//
    ft_putendl("");
    ft_putendl("Map empty is");//
    ft_putendl(map);//
    while (--p_qty >= 0)
    {   
        ft_putstr("\nPiece : ");//
        ft_putendl_nbr(p_qty);//    
        ft_putstr("X : ");//
        ft_putendl_nbr(tab[p_qty].pos.x);//    
        ft_putstr("Y : ");//
        ft_putendl_nbr(tab[p_qty].pos.y);//
        while (k++ < 16)
        {             
            if ((tab[p_qty].compbin & (0b1 << k)) != 0)
            {
                ft_putstr("letter index : ");//
                ft_putendl_nbr(((tab[p_qty].pos.y + k / 4) * (m_size + 1)) + (tab[p_qty].pos.x + k % 4)); //                   
                map[((tab[p_qty].pos.y + k / 4) * (m_size + 1)) + (tab[p_qty].pos.x + k % 4)] = p_qty + 'A';
            }
        }
        k = 0;
    }
    ft_putendl("\nMap full is");//
    ft_putendl(map);
}
