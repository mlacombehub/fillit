/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:22:38 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/12 13:18:28 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** We verify the minimal map size
*/

int		ft_sizeofmap(int ret)
{
	size_t	i;
	int		min;

	i = 0;
	min = ret * 4;

	while (i++)
		if (i * i >= min)
			break;
	return (i);
}


 void	ft_remover(t_piece piece, uint16_t *map)
 {

 }
/*
** We solve the placement of tetrimini on the map
*/

void	ft_placer(t_piece piece, uint16_t *map)
{
	/*
	line0 0b1111
	line1 0b11110000
	line2 0b111100000000
	line3 0b1111000000000000
	*/

	int j; // mask quarter increment
	int k; // abscisse shift
	int l; // line number between 0 and 15

	i = 0;
	j = 0;
	k = 0;
	//cut the piece in 4 lines
	// put it on the map
	// try and put on line 1, then 1 2 3
	// on first fail increment rightwise

	//while ( j < 4 && k < (sizeof(piece.compbin)* 8 - piece.width) && l < )
	while (k < (16 - piece.width) && l < (16 - piece.height))
	{
		while ( j < 4 )
			if ( (0b1111 << j*4) << k & piece.compbin) & map[l] && j < 4 )
				j++;
		j = 0;
		k++;
	}



}



/*
** We take the map, and put the pieces inside
*/

void ft_backtrack(t_piece *tab, int pieceqty, uint16_t *map)
{
	int i;
	int	j;
	int	map_side;

	i = 0;
	j = 1;
	// take piece 0 and put it on the map

	map_side = ft_sizeofmap(pieceqty);
	while ()
	{
		map_side++;
	}



}
