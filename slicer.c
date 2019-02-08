/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slicer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:10:53 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/08 18:13:11 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/fillit.h"

/*
** takes a char representing a tetrimino on a map
** and the horizontal side length of the map
** return the max size of any row
*/

int			ft_measurewidth(uint16_t binsrc, size_t s)
{
	size_t		k;
	uint16_t 	col_mask;

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
	int 		k;

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
** bitcompact : compacts a tetrimino : psuhes it up and left
** takes a bit and assuming column number is squareSide will
** shift it up and left
** 	if first col empty, shift by 1
**	need to create a mask of col
**	if first row empty shift by row size sidesize
**	we shoudl go max to sidesize loop but can stop before
*/

int		ft_bitcompact(int bitmino, int sidesize)
{
	uint16_t 	col_mask;
	uint16_t	row_mask;
	int 		k;

	row_mask = ft_power(2, sidesize) - 1;
	k = sidesize;
	while (k-- != 0)
			col_mask = 1 + (col_mask << sidesize);
	//while ((bitmino & (0b1111)) == 0)
	while ((bitmino & row_mask) == 0)
		bitmino = bitmino >> sidesize;
	//while ((bitmino & 0b1000100010001) == 0)
	while ((bitmino & col_mask) == 0)
		bitmino = bitmino >> 1;
	return (bitmino);
}

/*
** takes a string and for every char thebitchar
** sets the reversed n bit as 1.
** "1010" gives 5, so does "101"
*/

uint16_t	ft_rev_chartobit(char *src, char thebitchar)
{
	int 		k;
	uint16_t 	intbit;
	int 		power;

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
** returns a table of pieces structs
*/

void		ft_feedtopieces(t_piece *tab, char *feed)
{
	int 		k;

//ft_putnbr(ft_rev_chartobit("..##\n..##", '#'));ft_putendl("");//

	k = 0;
	while (*feed)
	{
		ft_putstr("\n mino no ");//
		ft_putendl_nbr(k);//
		tab[k].num_piece = k;
		ft_strcpy(tab[k].tetchar, ft_strsub(feed, 0, 21));
		tab[k].refbin = ft_rev_chartobit(tab[k].tetchar, '#');
		ft_putendl(tab[k].tetchar);//
		ft_putstr(" => equals ");//
		ft_putendl_nbr(tab[k].refbin);//
		tab[k].compbin = ft_bitcompact(tab[k].refbin, 4);
		tab[k].width = ft_measurewidth(tab[k].compbin, 4);
		tab[k].height = ft_measureheight(tab[k].compbin, 4);
		ft_putstr("w = ");//
		ft_putendl_nbr(tab[k].width);
		ft_putstr("h = ");//
		ft_putendl_nbr(tab[k].height);//
		ft_printmino(tab[k].refbin, 4);//
		ft_printmino(tab[k].compbin, 4);//
		k++;
		feed += 21;
	}
}
