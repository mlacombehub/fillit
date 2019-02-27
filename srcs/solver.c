/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:22:38 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/27 13:57:01 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Put each line one by one at position shifted by column and line as passed
** Adding the bits on the line is made with OR
*/

static void	ft_putpiece(t_piece *tab, unsigned short p_id, uint16_t *map)
{
	unsigned short	mask;

	mask = 0;
	while (mask < 4)
	{
		map[tab[p_id].pos.y + mask] = map[tab[p_id].pos.y + mask] + (((0b1111
		<< (mask * 4)) & tab[p_id].compbin) >> (mask * 4) << tab[p_id].pos.x);
		mask++;
	}
}

/*
** Remove each line one by one at position shifted by column and line as passed
** Removing the bits on the line is made with XOR
*/

static void	ft_removepiece(t_piece *tab, unsigned short p_id, uint16_t *map)
{
	unsigned short	mask;

	mask = 0;
	while (mask < 4)
	{
		map[tab[p_id].pos.y + mask] = map[tab[p_id].pos.y + mask] ^ (((0b1111
		<< (mask * 4)) & tab[p_id].compbin) >> (mask * 4) << tab[p_id].pos.x);
		mask++;
	}
	tab[p_id].pos.x = 0;
	tab[p_id].pos.y = 0;
}

/*
** easier : put the mino into a 64 int
** this way we just mask over the first
** 4 lines started at the map first line (int16)
*/

static int	ft_placer(t_piece *tab, unsigned short p_id, uint16_t *map
			, unsigned short m_size)
{
	int			l;
	int			c;
	uint64_t	*map64;

	l = -1;
	map64 = NULL;
	while ((tab[p_id].size.y + l++) < m_size)
	{
		c = -1;
		while ((tab[p_id].size.x + c++) < m_size)
		{
			map64 = (uint64_t *)(map + l);
			if (((tab[p_id].movbin << c) & *map64) == 0)
			{
				tab[p_id].pos.x = c;
				tab[p_id].pos.y = l;
				ft_putpiece(tab, p_id, map);
				if (tab[p_id].islast || ft_placer(tab, p_id + 1, map, m_size))
					return (TRUE);
				ft_removepiece(tab, p_id, map);
			}
		}
	}
	return (FALSE);
}

/*
** We take the map, and put the pieces inside
*/

int			ft_mapbuilder(t_piece *tab, unsigned short p_qty, uint16_t *map)
{
	unsigned short	m_size;

	m_size = 2;
	while (m_size * m_size < 4 * p_qty)
		m_size++;
	while (!(ft_placer(tab, 0, map, m_size)) && m_size++ <= 16)
		ft_bzero(map, sizeof(*map) * 16);
	return (m_size);
}
