/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:07:31 by xbarthe           #+#    #+#             */
/*   Updated: 2019/01/23 23:15:14 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"
/*
**     AND (mask : x) = x then can shift 
** 
** in header macro define #define b0  0x0001
** #define b1  0x0002
** #define b2  0x0004
** #define b3  0x0008
** #define b4  0x0010 etc.. 
** 
** add to libft a ft_bin_as_str_to_int
*/

int    ft_bitcompact(int bitmino)
{

    return (bitmino);
}

/*
** takes a string and for every char theBitChar 
** sets the reversed n bit as 1.
** "1010" gives 5, so does "101"
*/

int     ft_revCharToBit(char *c, char theBitChar)
{
    int k;
    int intBit;
    int power;

    intBit = 0;
    k = 0;
    power = 1;
    while (c[k] != '\0')
    {
        if (c[k] == theBitChar)
            intBit = intBit + power;
        power = power * 2;
        k++;
    }
    return intBit;
}

/*
** takes a string and for every n char as theBitChar 
** sets the n bit as 1
** "1010" gives 10
*/

int     ft_charToBit(char *c, char theBitChar)
{
    int k;
    int intBit;
    int power;

    intBit = 0;
    k = ft_strlen(c);
    power = 1;
    while (k-- != 0)
    {
        if (c[k] == theBitChar)
            intBit = intBit + power;
        power = power * 2;
    }
    return intBit;
}
