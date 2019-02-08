/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slicer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:10:53 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/08 13:27:31 by xbarthe          ###   ########.fr       */
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
	int			w;

	col_mask = 1;
	w = 0;
	//colmask = 0b1000000000000000100000000000000010000000000000001;
	k = sizeof(binsrc) / s;
	while ( k-- != 0)
			col_mask = col_mask + ft_power(2, k);
	while ((binsrc & col_mask) != 0)
	{
		w++;
		col_mask = col_mask >> 1;
	}
	return (w);
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

	h = 0;
	//rowmask = 0b1111111111111111;
	row_mask = ft_power(2, s) - 1;
	while ((binsrc & row_mask) != 0)
	{
		h++;
		row_mask = row_mask >> s;
	}
	return (h);
}

/*
** calculates 'nb' to the power 'power'
*/

uint16_t	ft_power(uint16_t nb, int power)
{
	int	i;
	int	result;

	i = 1;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power == 0)
		return (1);
	while (i++ < power)
		result = result * nb;
	return (result);
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
		ft_putstr("\n mino no ");ft_putnbr(k); ft_putendl("");//
		tab[k].num_piece = k;
		ft_strcpy(tab[k].tetchar, ft_strsub(feed, 0, 21));

		tab[k].refbin = ft_rev_chartobit(tab[k].tetchar, '#');
		ft_putendl(tab[k].tetchar); ft_putstr(" => equals ");
		ft_putnbr(tab[k].refbin);ft_putendl("");//
		tab[k].width = ft_measurewidth(tab[k].refbin, 4);
		tab[k].height = ft_measureheight(tab[k].refbin, 4);
		ft_putstr("w = ");ft_putnbr(tab[k].width);ft_putendl("");//
		ft_putstr("h = ");ft_putnbr(tab[k].height);ft_putendl("");//
		k++;
		feed += 21;
		ft_printmino(tab[k].refbin, 4);//
	}
}
