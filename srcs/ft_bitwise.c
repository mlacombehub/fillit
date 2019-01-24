/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:48:24 by xbarthe           #+#    #+#             */
/*   Updated: 2019/01/24 18:03:36 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

// /*
// **	 AND (mask : x) = x then can shift
// **
// **
// ** in header macro define #define b0  0x0001
// ** #define b1  0x0002
// ** #define b2  0x0004
// ** #define b3  0x0008
// ** #define b4  0x0010 etc..
// **
// ** add to libft a ft_bin_as_str_to_int
// **
// ** CAREFUL we should rather use unsigned int or size_t to avoid any
// ** fishy business with shifting in negative numbers
// */

/*
** bitcompact : compacts a tetrimino : psuhes it up and left
** takes a bit and assuming column number is squareSide will
** shift it up and left
**
*/

int		ft_bitcompact(int bitmino, int sidesize)
{
	// if first col empty, shift by 1
	// need to create a mask of col
	// if first row empty shift by row size sidesize
	// we shoudl go max to sidesize loop but can stop before
	(void) sidesize;
	return (bitmino);
}

/*
** this is the valid function //
** takes a string and for every char thebitchar
** sets the reversed n bit as 1.
** "1010" gives 5, so does "101"
*/

int		ft_rev_chartobit(char *c, char thebitchar)
{
	int k;
	int intbit;
	int power;

	intbit = 0;
	k = 0;
	power = 1;
	while (c[k] != '\0')
	{
		if (c[k] == thebitchar)
			intbit = intbit + power;
		power = power * 2;
		k++;
	}
	return (intbit);
}

/*
** ignore this function, it skips too many zeroes
** takes a string and for every n char as thebitchar
** sets the n bit as 1
** "1010" gives 10
*/

int		ft_right_chartobit(char *c, char thebitchar)
{
	int k;
	int intbit;
	int power;

	intbit = 0;
	k = ft_strlen(c);
	power = 1;
	while (k-- != 0)
	{
		if (c[k] == thebitchar)
			intbit = intbit + power;
		power = power * 2;
	}
	return (intbit);
}

/*
** ignore this function, it skips too many zeroes
** takes a string and for every n char as thebitchar
** sets the n bit as 1
** passes the big or little endian
*/

int		ft_chartobit(char *c, char thebitchar, int bigendian)
{
	int k;
	int intbit;
	int power;

	intbit = 0;
	k = (bigendian ? ft_strlen(c) : 0);
	power = 1;
	while ((bigendian == 1 && k != 0) || (bigendian == 0 && c[k] != '\0'))
	{
		if (c[k] == thebitchar)
			intbit = intbit + power;
		power = power * 2;
		if (bigendian == 1)
			k--;
		else
			k++;
	}
	return (intbit);
}
