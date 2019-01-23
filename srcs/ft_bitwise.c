/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:07:31 by xbarthe           #+#    #+#             */
/*   Updated: 2019/01/24 00:03:34 by xbarthe          ###   ########.fr       */
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
**
** CAREFUL we should rather use unsigned int or size_t to avoid any 
** fishy business with shifting in negative numbers
*/

/*
** takes a bit and assuming column number is squareSide will shift it up and left
*/

int    ft_bitcompact(int bitmino, int squareSide)
{
    // if first col empty, shift by 1
    // need to create a mask of col 
    // if first row empty shift by row size squareSide
    // we shoudl go max to squareSide loop but can stop before
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

int     ft_rightCharToBit(char *c, char theBitChar)
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

/*
** takes a string and for every n char as theBitChar 
** sets the n bit as 1
** passes the big or little endian
*/

int     ft_charToBit(char *c, char theBitChar, int bigEndian)
{
    int k;
    int intBit;
    int power;

    intBit = 0;
    k = (bigEndian ? ft_strlen(c) : 0);
    power = 1;
    while ((bigEndian == 1 && k != 0) || (bigEndian == 0 && c[k] != '\0'))
    {
        if (c[k] == theBitChar)
            intBit = intBit + power;
        power = power * 2;
        if (bigEndian == 1)
            k--; 
        else
            k++;
    }
    return intBit;
}
