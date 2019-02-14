/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:22:38 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/14 12:16:53 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"


/*
** cut the piece in 4 lines
** put it on the map
** try and put on line 1, then 1 2 3
** on first fail increment rightwise
** on end of map (over the side) increment downwise
*/

int ft_piececanbeput(t_piece *tab, int num_piece, uint16_t *map, int map_side)
{
	int	mask_increment;
	int shift_column;
	int shift_line;

	mask_increment = 0;
	shift_column = 0;
	shift_line = 0;
	while ((tab[num_piece].size.y + shift_line) < map_side)
	{
		while ((tab[num_piece].size.x + shift_column) < map_side && shift_line++)
			while (mask_increment < 4)
				if ((((0b1111 << mask_increment * 4) & tab[num_piece].compbin) << shift_column)	& map[shift_line + mask_increment++])
				{
					if (mask_increment == 3)
						return(1);
				}
				else
				{
					shift_column++;
					mask_increment = 0;
					break;
				}
		shift_column = 0;
		shift_line++;
	}				// save position of piece on map
	return (0);
}


/*
** Put each line one by one at position shifted by column and line as passed
** Adding the bits on the line is made with OR
*/

void	ft_putpiece(t_piece *tab, int num_piece, uint16_t *map, int shift_column, int shift_line)
{
	int	mask_increment;

	mask_increment = 0;
	while (mask_increment++ < 4)
		map[shift_line + mask_increment] = map[shift_line + mask_increment] | (((0b1111 << mask_increment * 4) & tab[num_piece].compbin) << shift_column);
	tab[num_piece].origpos.x = shift_column;
	tab[num_piece].origpos.y = shift_line;
}

/*
** Remove each line one by one at position shifted by column and line as passed
** Removing the bits on the line is made with XOR
*/

void	ft_removepiece(t_piece *tab, int num_piece, uint16_t *map)
{
	int	mask_increment;
	int shift_column;
	int shift_line;

	mask_increment = 0;
	shift_column = tab[num_piece].origpos.x;
	shift_line = tab[num_piece].origpos.y;

	while (mask_increment++ < 4)
		map[shift_line + mask_increment] = map[shift_line + mask_increment] ^ (((0b1111 << mask_increment * 4) & tab[num_piece].compbin) << shift_column);
	tab[num_piece].origpos.x = 0;
	tab[num_piece].origpos.y = 0;
}

/*
** We solve the placement of tetrimini on the map
**	line0 0b1111
**	line1 0b11110000
**	line2 0b111100000000
**	line3 0b1111000000000000
*/

int			ft_placer(t_piece *tab, size_t map_side, uint16_t *map, int pieceqty)
{
	int	num_piece; // num of piece
	int	mask_increment; // mask quarter increment
	int	shift_column; // abscisse shift
	int	shift_line; // line number between 0 and 15

	num_piece = 0;
	mask_increment = 0;
	shift_column = 0;
	shift_line = 0;

	if (ft_piececanbeput(tab, num_piece,*map , map_side).x = -1)
	{
		ft_putpiece(tab, num_piece, map, shift, shift_column)
		num_piece++;
	}
	else
	{
	removepiece(numpiece--);
	}

	function piececanbeput(piece);


	while (piececanbeput[num_piece])
		putpiece;
		try next piece;

	num_piece;
}

/*
** We take the map, and put the pieces inside
*/

uint16_t	*ft_mapbuilder(t_piece *tab, int pieceqty, uint16_t *map)
{
	size_t	map_side;

	map_side = 2;
	while (map_side * map_side < 4 * pieceqty)
		map_side++;
	while (!ft_placer(tab, map_side, map, pieceqty))
	{
		ft_bzero(map, sizeof(map) * 16);
		map_side++;
	}
	return (map);
}
