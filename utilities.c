/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:39:57 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/20 23:27:10 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

/*
** takes an int and print it out as square
** do a >> shift of squareside and set above squareside to 0
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
            ft_putendl_nbr(newmino & 1);
            newmino = newmino >> 1;
        }
    }
}

void    ft_printmap(t_piece *tab, int m_size, int p_qty)
{
    char    map[m_size * (m_size + 1)];
    int     k;


    k = m_size * (m_size + 1);//
    map[k - 1] = '\0';
    // ft_putstr(" map in char ");//
    // ft_putendl(map);//
    // ft_putstr(" k ");//
    // ft_putendl_nbr(k);//
    // ft_putstr(" map size ");//
    // ft_putendl_nbr(m_size);//
    while (--k >= 1)
    {
        if (k % (m_size + 1) == 0 && k != 0)
            map[k - 1] = '\n';
        else
           map[k - 1] = '.';
    }

    // ft_putstr("str len  : ");//
    // ft_putendl_nbr(ft_strlen(map));//
    // ft_putstr(" k ");//
    // ft_putendl_nbr(k);//

    ft_putendl("\nMap empty is");//
    ft_putendl(map);//
    while (--p_qty >= 0)
    {
        ft_putstr("\nPiece: no = ");//
        ft_putnbr(p_qty);//
        ft_putstr(" value = ");//
        ft_putnbr(tab[p_qty].compbin);//
        ft_putstr(" X : ");//
        ft_putnbr(tab[p_qty].pos.x);//
        ft_putstr(" Y : ");//
        ft_putendl_nbr(tab[p_qty].pos.y);//
        while (k < 16)
        {
            if ((tab[p_qty].compbin & (0b1 << k)) != 0)
            {
<<<<<<< HEAD
                // ft_putstr("letter index : ");//
                // ft_putendl_nbr(((tab[p_qty].pos.y + k / 4) * (m_size + 1)) + (tab[p_qty].pos.x + k % 4));//
                map[((tab[p_qty].pos.y + k / 4) * (m_size + 1))
                + (tab[p_qty].pos.x + k % 4)] = p_qty + 'A';
=======
                ft_putstr("letter index : ");//
                ft_putendl_nbr(((tab[p_qty].pos.y + k / 4) * (m_size + 1)) + (tab[p_qty].pos.x + k % 4));//
                map[((tab[p_qty].pos.y + k / 4) * (m_size + 1)) + (tab[p_qty].pos.x + k % 4)] = p_qty + 'A';
>>>>>>> 742a28ae616a68a5a94c46ca37ed1bb339a7c3dc
            }
            k++;
        }
        k = 0;
    }
    ft_putendl("\nMap full is");//
    ft_putendl(map);
}

<<<<<<< HEAD
void    ft_print_bytes(void *ptr, int size)
=======
/*
** prints the bytes from memory
** we print from the [ptr] address, [size] bytes grouping by [step] 
** prefixing with grouping number
** if step is 0 we juste print separated by space
*/

void ft_print_bytes(void *ptr, int size, int step)
>>>>>>> 742a28ae616a68a5a94c46ca37ed1bb339a7c3dc
{
    unsigned char *p = ptr;
    int i;

    if (ptr)
    {
        i = 0;
        while (i++ < size)
        {
<<<<<<< HEAD
            ft_print_bits(p[i]);
            ft_putstr(" ");
=======
            if ( step != 0 && i % step == 0)
            {
                ft_putnbr(i / step);
                ft_putstr(" ");
            }
            //printf("%02hhX ", p[i]);
            ft_print_bits(p[i]);
            ft_putstr(" ");
            i++;
            if ( step != 0 && i % step == 0)
                 ft_putstr("\n");
>>>>>>> 742a28ae616a68a5a94c46ca37ed1bb339a7c3dc
        }
    }
    else
        ft_putstr("[NULL pointer]");
    ft_putstr("\n");
}
