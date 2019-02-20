/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slicer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:10:53 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/20 15:43:05 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

/*
** Trying to fuse measureheight and measurewidth
*/

int			ft_measure_w_h(uint16_t binsrc, int sx, int sy, int sside)
{
	int			k;
	uint16_t	col_mask;
	uint16_t	row_mask;

	k = sside;
	if (sx == 0)
	{
		sx = sside;
		while (sside-- != 0)
			col_mask = ft_power(2, sx - 1) + (col_mask << sx);
		while ((binsrc & col_mask) == 0 && sx--)
			col_mask = col_mask >> 1;
		return (sx);
	}
	else
	{
		sy = sside;
		row_mask = ft_power(2, sside) - 1;
		while (k-- != 1)
			row_mask = row_mask << sside;
		while ((binsrc & row_mask) == 0 && sy--)
			row_mask = row_mask >> sside;
		return (sy);
	}
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
	uint64_t	longcomp;
	uint64_t	longbit;
	int			k;

	k = 0;
	longbit = 0;
	longcomp = (uint64_t)compbit;
	while (k < sidesize)
	{
		longbit = longbit + (((0b1111 << (k * sidesize))
		& longcomp) << ((16 - sidesize) * k));
		k++;
	}
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
	ft_putendl("\nfeed :");//
	ft_putendl(feed);//
	ft_putendl_nbr(k);//
	while (feed && *feed)
	{
		ft_putendl("arrivee dans feedtopieces, lancement de la creation de tab");//
		tab[k].p_id = k + 'A';
		ft_strncpy(tab[k].tetchar, feed, 21);
		ft_putendl("ecriture dans refbin");//
		tab[k].refbin = ft_rev_chartobit(tab[k].tetchar, '#');
		ft_putendl("ecriture dans compbin");//
		tab[k].compbin = ft_bitcompact(tab[k].refbin, 4);
		ft_putendl("ecriture dans movbin");//
		tab[k].movbin = ft_bit16to64(tab[k].compbin, 4);
		ft_putendl("ecriture dans size.x");//
		tab[k].size.x = 0;
		tab[k].size.y = 0;
		tab[k].size.x = ft_measure_w_h(tab[k].compbin, tab[k].size.x, tab[k].size.y, 4);
		ft_putendl("ecriture dans size.y");//
		tab[k].size.y = ft_measure_w_h(tab[k].compbin, tab[k].size.x, tab[k].size.y, 4);
		tab[k].pos.x = 0;
		tab[k].pos.y = 0;
		k++;
		feed += 21;
	}
	ft_putendl("movbin");//
	ft_putendl_nbr(tab[k].movbin);//
	while (k-- != 0)
	{
		ft_putendl("");//
		ft_putchar('A' + k);//
		ft_putendl("");//
		ft_putendl(tab[k].tetchar);//
	}
}
