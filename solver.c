/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:22:38 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/14 13:07:21 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

/*
** cut the piece in 4 lines
** put it on the map
** try and put on line 1, then 1 2 3
** on first fail increment rightwise
** on end of map (over the side) increment downwise
** we use these masks for taking only the 4 bits needed
**	line0 0b1111
**	line1 0b11110000
**	line2 0b111100000000
**	line3 0b1111000000000000
*/

void ft_piececanbeput(t_piece *tab, int p_id, uint16_t *map, int m_size)
{
	int	mask;

	mask = 0;
	tab[p_id].pos.x = 0;
	tab[p_id].pos.y = 0;
	while ((tab[p_id].size.y + tab[p_id].pos.y) < m_size)
	{
		while ((tab[p_id].size.x + tab[p_id].pos.x) < m_size && tab[p_id].pos.y++)
			while (mask < 4)
			{
				if ((((0b1111 << mask * 4) & tab[p_id].compbin) << tab[p_id].pos.x) & map[tab[p_id].pos.y + mask++])
				{
					if (mask == 3)
						exit;
				}
				else
				{
					tab[p_id].pos.x++;
					mask = 0;
					break;
				}
			}
		tab[p_id].pos.x = 0;
		tab[p_id].pos.y++;
	}				// save position of piece on map
	tab[p_id].pos.x = -1;
	tab[p_id].pos.y = -1;
}


/*
** Put each line one by one at position shifted by column and line as passed
** Adding the bits on the line is made with OR
*/

void	ft_putpiece(t_piece *tab, int p_id, uint16_t *map, int shift_c, int shift_l)
{
	int	mask;

	mask = 0;
	while (mask++ < 4)
		map[shift_l + mask] = map[shift_l + mask] | (((0b1111 << mask * 4) & tab[p_id].compbin) << shift_c);
	tab[p_id].pos.x = shift_c;
	tab[p_id].pos.y = shift_l;
}

/*
** Remove each line one by one at position shifted by column and line as passed
** Removing the bits on the line is made with XOR
*/

void	ft_removepiece(t_piece *tab, int p_id, uint16_t *map)
{
	int	mask;
	int shift_c;
	int shift_l;

	mask = 0;
	shift_c = tab[p_id].pos.x;
	shift_l = tab[p_id].pos.y;

	while (mask++ < 4)
		map[shift_l + mask] = map[shift_l + mask] ^ (((0b1111 << mask * 4) & tab[p_id].compbin) << shift_c);
	tab[p_id].pos.x = 0;
	tab[p_id].pos.y = 0;
}

/*
** We try and place the piece
** if the piece can be put, we have a pos x y and we put the piece
** if it can't we increase the map size
*/

int			ft_placer(t_piece *tab, size_t m_size, uint16_t *map, int pieceqty)
{
	int	p_id; // num of piece

	p_id = 0;
	ft_piececanbeput(tab, p_id, map , m_size);
	if (tab[p_id].pos.x != -1)
	{
		ft_putpiece(tab, p_id, map, shift, shift_c)
		p_id++;
	}

// remove recursively
	{
	ft_removepiece(tab, p_id, map);
	}
}

/*
** We take the map, and put the pieces inside
*/

uint16_t	*ft_mapbuilder(t_piece *tab, int pieceqty, uint16_t *map)
{
	size_t	m_size;

	m_size = 2;
	while (m_size * m_size < 4 * pieceqty)
		m_size++;
	while (!ft_placer(tab, m_size, map, pieceqty))
	{
		ft_bzero(map, sizeof(map) * 16);
		m_size++;
	}
	return (map);
}
