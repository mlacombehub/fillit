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

void	ft_remover(t_piece piece, uint16_t *map)
{

}

/*
** We solve the placement of tetrimini on the map
*/

int	ft_placer(t_piece *tab, size_t map_side, uint16_t *map)
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

<<<<<<< HEAD
	if ( (0b1111 << j*4) << k & piece.compbin) & map[l])
=======
	//while ( j < 4 && k < (sizeof(piece.compbin)* 8 - piece.width) && l < )
	while (k < (16 - piece.width) && l < (16 - piece.height))
>>>>>>> 9bedf6b62b0a40ede62e268ba465855f5c18235f
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

uint16_t ft_backtrack(t_piece *tab, int pieceqty, uint16_t *map)
{
	size_t	map_side;

	while (map_side * map_side < 4 * pieceqty)
		map_side++;
	while (!ft_placer(tab, map_side, map) && map_side < 17)
	{
		ft_bzero(map, sizeof(map) * 16);
		map_side++;
	}
	return ();
}
