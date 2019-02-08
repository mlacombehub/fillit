/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:48:24 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/07 19:56:36 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fillit.h"

uint16_t		ft_power(uint16_t nb, int power);
/*
**	 AND (mask : x) = x then can shift
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
**
**********************
**
** bitcompact : compacts a tetrimino : psuhes it up and left
** takes a bit and assuming column number is squareSide will
** shift it up and left
**
** 	if first col empty, shift by 1
**	need to create a mask of col
**	if first row empty shift by row size sidesize
**	we shoudl go max to sidesize loop but can stop before
*/

int		ft_bitcompact(int bitmino, int sidesize)
{
	while ((bitmino & (0b1111)) == 0)
		bitmino = bitmino >> sidesize;
	while ((bitmino & 4369) == 0)
		bitmino = bitmino >> 1;
	return (bitmino);
}

/*
** this is the valid function //
** takes a string and for every char thebitchar
** sets the reversed n bit as 1.
** "1010" gives 5, so does "101"
*/

uint16_t	ft_rev_chartobit(char *c, char thebitchar)
{
	int k;
	uint16_t intbit;
	int power;

	intbit = 0;
	k = 0;
	power = 1;
	while (c[k] != '\0')
	{
		if (c[k] == thebitchar)
			intbit = intbit + power;
		if (c[k] != '\n')
			power = power * 2;
		k++;
	}
	return (intbit);
}

int		ft_putpiece(t_map * map, uint16_t piece)
{
	// try and put piece in map 0
	if ( (map->mappart[1] & piece)== 0) // can be matched as no overlap
		map->mappart[1] = map->mappart[1] | piece; // add it with OR
	else // try and move the piece sideway
		(void)1;
	// check map is not too large
	// try and move down
	// check map not too high
	return (1);

}

int		ft_measurewidth(uint16_t stuff, size_t s)
{
	size_t		k;
	uint16_t 	col_mask;
	int			w;

	col_mask = 1;
	w = 0;
	//colmask = 0b1000000000000000100000000000000010000000000000001;
	k = sizeof(stuff) / s;
	while ( k-- != 0)
			col_mask = col_mask + ft_power(2, k);
	while ((stuff & col_mask) != 0)
	{
		w++;
		col_mask = col_mask >> 1;
	}
	return (w);
}

int		ft_measureheight(uint16_t stuff, size_t s)
{
	uint16_t	row_mask;
	int			h;

	h = 0;
	//rowmask = 0b1111111111111111;
	row_mask = ft_power(2, s) - 1;
	while ((stuff & row_mask) != 0)
	{
		h++;
		row_mask = row_mask >> s;
	}
	return (h);
}
