/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slicer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:10:53 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/18 18:04:36 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

/*
** takes a char representing a tetrimino on a map
** and the horizontal side length of the map
** return the max size of any row
*/

int			ft_measurewidth(uint16_t binsrc, size_t s)
{
	size_t		k;
	uint16_t	col_mask;

	k = s;
	while (k-- != 0)
		col_mask = ft_power(2, s - 1) + (col_mask << s);
	while ((binsrc & col_mask) == 0 && s--)
		col_mask = col_mask >> 1;
	return (s);
}

/*
** takes a char representing a tetrimino on a map
** and the vertical side length of the map
** returns the max size of any column
*/

int			ft_measureheight(uint16_t binsrc, size_t s)
{
	uint16_t	row_mask;
	int			h;
	int			k;

	h = s;
	k = s;
	row_mask = ft_power(2, s) - 1;
	while (k-- != 1)
		row_mask = row_mask << s;
	while ((binsrc & row_mask) == 0 && h--)
		row_mask = row_mask >> s;
	return (h);
}

/*
** bitcompact : compacts a tetriminoin binary :
** pushes it up and left
** takes a bit and assuming column / row number is sidesize
** 	if first col empty, shift by 1
**	if first row empty shift by row size sidesize
**	we should go max to sidesize loop but can stop before
**	for size 4 mask col = 0b1000100010001 mask row = 0b1111
*/

int			ft_bitcompact(int bitmino, int sidesize)
{
	uint16_t	col_mask;
	uint16_t	row_mask;
	int			k;

	row_mask = ft_power(2, sidesize) - 1;
	k = sidesize;
	while (k-- != 0)
		col_mask = 1 + (col_mask << sidesize);
	while ((bitmino & row_mask) == 0)
		bitmino = bitmino >> sidesize;
	while ((bitmino & col_mask) == 0)
		bitmino = bitmino >> 1;
	return (bitmino);
}

/*
** ft_bit16to64 : takes a compact 16 bit and expand it over 64 :
** each 4 pix, shift by 12
*/

uint64_t	ft_bit16to64(int compbit, int sidesize)
{
	uint64_t	longbit;
	int			k;

	k = 0;
	longbit = 0;
	while (k < sidesize)
		longbit += (((0b1111 << k * 4) & compbit) << 16 * k);
	return (longbit);
}


/*
** takes a string and for every n-th char thebitchar
** sets the reversed n bit as 1.
** "1010" gives 5, so does "101"
*/

uint16_t	ft_rev_chartobit(char *src, char thebitchar)
{
	int			k;
	uint16_t	intbit;
	int			power;

	intbit = 0;
	k = 0;
	power = 1;
	while (src[k] != '\0')
	{
		if (src[k] == thebitchar)
			intbit = intbit + power;
		if (src[k] != '\n')
			power = power * 2;
		k++;
	}
	return (intbit);
}

/*
** takes a string and splits it into all the pieces
** updates the pointer to a table of pieces structs
** TODO remove the debug output
*/

void		ft_feedtopieces(t_piece *tab, char *feed)
{
	int k;

	k = 0;
	while (*feed)
	{
		tab[k].p_id = k + 'A';
		ft_strcpy(tab[k].tetchar, ft_strsub(feed, 0, 21));
		tab[k].refbin = ft_rev_chartobit(tab[k].tetchar, '#');
		tab[k].compbin = ft_bitcompact(tab[k].refbin, 4);
		tab[k].movbin = ft_bit16to64(tab[k].compbin, 4);
		tab[k].width = ft_measurewidth(tab[k].compbin, 4);
		tab[k].height = ft_measureheight(tab[k].compbin, 4);
		tab[k].size.x = ft_measurewidth(tab[k].compbin, 4);
		tab[k].size.x = ft_measureheight(tab[k].compbin, 4);
		tab[k].pos.x = 0;
		tab[k].pos.x = 0;
		k++;
		feed += 21;
	}
	//below is debug display, can be removed (or activate with debug 1)
	while (k-- != 0)
	{
		ft_putchar('A' + k);
		ft_putendl("");
		ft_putendl(tab[k].tetchar);
	}
}
