/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:22:38 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/19 14:16:28 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"



/*
** easier : put the mino into a 64 int
** this way we just mask over the first 4 lines started at the map first line (int16)
*/

int	ft_put64piece(t_piece *tab, int p_id, uint16_t *map, int m_size, int p_qty)
{
	int			l;//line
	int			c;//column
	uint64_t	map64;

	l = 0;
	// check we are at the last piece
	printf("p_id : %i\n", p_id);//
	printf("p_qty : %i\n", p_qty);//
	if (p_id >= p_qty)
		return (1);
	printf("entree dans la boucle de backtrack\n");//
	// so we don't go one further
	while ((tab[p_id].size.y + l) < m_size)
	{
		printf("tab[p_id].size.y : %i\n", tab[p_id].size.y);//
		printf("l : %i\n", l);//
		c = 0;
		while ((tab[p_id].size.x + c) < m_size)
		{
			printf("tab[p_id].size.x : %i\n", tab[p_id].size.x);//
			printf("c : %i\n\n", l);//
			map64 = (uint64_t)map[l];
			if (((tab[p_id].movbin << c) & map64) == 0)
			{
				printf("entree dans le test de recursivite\n");//
				tab[p_id].pos.x = c;
				tab[p_id].pos.y = l;
				ft_putpiece(tab, p_id, map);
				//can be put here
				if	(ft_put64piece(tab,  p_id + 1, map, m_size, p_qty))
					return (1);
				else
				{
					printf("remove piece\n");//
					ft_removepiece(tab, p_id, map);
					c++;
				}
			}
		}
		l++;
	}
	return(0);
}

/*
** cut the piece in 4 lines
** put it on the map
** (we start at 0,0 for each piece, unless we find another x value
** because it is a second try)
** try and put on line 1, then 1 2 3
** on first fail increment rightwise
** on end of map (over the side) increment downwise
** we use these masks for taking only the 4 bits needed
**	line0 0b1111
**	line1 0b11110000
**	line2 0b111100000000
**	line3 0b1111000000000000
*/

int ft_piececanbeput(t_piece *tab, int p_id, uint16_t *map, int m_size)
{
	int	mask;

	mask = 0;
	tab[p_id].pos.x = (tab[p_id].pos.x <= 0 ? 0 : tab[p_id].pos.x);
	tab[p_id].pos.y = (tab[p_id].pos.y <= 0 ? 0 : tab[p_id].pos.y);
	while ((tab[p_id].size.y + tab[p_id].pos.y) < m_size)
	{
		while (((tab[p_id].size.x + tab[p_id].pos.x) < m_size
		&& tab[p_id].pos.y++) && (mask < 4))
			if ((((0b1111 << mask * 4) & tab[p_id].compbin) << tab[p_id].pos.x)
			& map[tab[p_id].pos.y + mask] && mask++ <= 3)
				return(1);//exit if no return
			else if ((((0b1111 << mask * 4) & tab[p_id].compbin)
			<< tab[p_id].pos.x) & map[tab[p_id].pos.y + mask])
			{
				tab[p_id].pos.x++;
				mask = 0;
				break;
			}
		tab[p_id].pos.x = 0;
	}
	tab[p_id].pos.x = -1;
	tab[p_id].pos.y = -1;
	return (0);// added return
}

/*
** Put each line one by one at position shifted by column and line as passed
** Adding the bits on the line is made with OR
*/

void	ft_putpiece(t_piece *tab, int p_id, uint16_t *map)
{
	int	mask;

	mask = 0;
	while (mask++ < 4)
		map[tab[p_id].pos.y + mask] = map[tab[p_id].pos.y + mask] | (((0b1111 << mask * 4) & tab[p_id].compbin) << tab[p_id].pos.x);
}

/*
** Remove each line one by one at position shifted by column and line as passed
** Removing the bits on the line is made with XOR
*/

void	ft_removepiece(t_piece *tab, int p_id, uint16_t *map)
{
	int	mask;

	mask = 0;
	while (mask++ < 4)
		map[tab[p_id].pos.y + mask] = map[tab[p_id].pos.y + mask] ^ (((0b1111 << mask * 4) & tab[p_id].compbin) << tab[p_id].pos.x);
	tab[p_id].pos.x = 0;
	tab[p_id].pos.y = 0;
}

/*
** We try and place the piece
** if the piece can be put, we have a pos x y not -1
** and we put the piece at the saved x and y
** If all pieces won't fit, we increase the map size and start anew at piece 0
** If at end of max map size no result, we start anew BUT we shift first piece
*/

int			ft_placer(t_piece *tab, int p_qty, size_t m_size, uint16_t *map)
{
	printf("entree dans ft_placer :\n");//
	return (ft_put64piece(tab, 0, map, m_size,p_qty));
}
	/*
** We take the map, and put the pieces inside
*/

uint16_t	*ft_mapbuilder(t_piece *tab, int p_qty, uint16_t *map)
{
	int	m_size;

	printf("calcul m_size min :\n");//
	m_size = 2;
	while (m_size * m_size < 4 * p_qty)
		m_size++;
	printf("%i\n", m_size);//
	//while (!ft_placer(tab, p_qty, m_size, map) && m_size <= 16)
	while (!(ft_put64piece(tab,  0, map, m_size, p_qty)) && m_size <= 16)
	{
		printf("remise a zero de la map\n");//
		ft_bzero(map, sizeof(*map) * 16);
		m_size++;
		printf("augmentation de la taille de map, m_size: %i\n", m_size);//
	}
	return (map);
}
