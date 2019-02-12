/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:22:38 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/11 18:42:06 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** We check if the piece can be placed on map
*/

void		ft_checker(t_piece piece, uint16_t *map)
{
	return (0);
}

/*
**  We remove the piece if it is not possible to make it go inside the map
*/

void		ft_remover(t_piece piece, uint16_t *map)
{
	return (0);
}

/*
** We solve the placement of tetrimini on the map
**	line0 0b1111
**	line1 0b11110000
**	line2 0b111100000000
**	line3 0b1111000000000000
*/

int			ft_placer(t_piece *tab, size_t map_side, uint16_t *map)
{
	int	i;
	int	j; // mask quarter increment
	int	k; // abscisse shift
	int	l; // line number between 0 and 15

	i = 0;
	j = 0;
	k = 0;
	l = 0;

	/*
	** cut the piece in 4 lines
	** put it on the map
	** try and put on line 1, then 1 2 3
	** on first fail increment rightwise
	*/

	while (((0b1111 << j*4) << k & tab[i].compbin) & map[l])
	{
		while ( j < 4 )
			if (((0b1111 << j*4) << k & tab[i].compbin) & map[l] && j < 4)
				j++;
		j = 0;
		k++;
	}
}

/*
** We take the map, and put the pieces inside
*/

uint16_t	ft_mapbuilder(t_piece *tab, int pieceqty, uint16_t *map)
{
	size_t	map_side;

	while (map_side * map_side < 4 * pieceqty)
		map_side++;
	while (!ft_placer(tab, map_side, map) && map_side < 17)
	{
		ft_bzero(map, sizeof(map) * 16);
		map_side++;
	}
	return (map);
}