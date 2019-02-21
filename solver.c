/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:22:38 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/20 23:31:05 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

/*
** easier : put the mino into a 64 int
** this way we just mask over the first
** 4 lines started at the map first line (int16)
*/

int	ft_put64piece(t_piece *tab, int p_id, uint16_t *map, int m_size, int p_qty, int compteur)
{
	int			l;//line
	int			c;//column
	uint64_t	*map64;

	l = 0;
	map64 = NULL;
	ft_putendl("\np_id :");//
	ft_putendl_nbr(p_id);//
	ft_putendl("p_qty :");//
	ft_putendl_nbr(p_qty);//
	if (p_id >= p_qty )
		return (1);
	ft_putstr("\nentree dans la boucle de backtrack n°");//
	ft_putendl_nbr(compteur);//
	// ft_putstr(" piece no :");//
	// ft_putendl_nbr(p_id);//
	// ft_putstr("tab[p_id].size.y : ");//
	// ft_putendl_nbr(tab[p_id].size.y);//
	ft_putstr("l : ");//
	ft_putendl_nbr(l);//
	while ((tab[p_id].size.y + l) <= m_size)
	{
		c = 0;
		// ft_putstr("tab[p_id].size.x : ");//
		// ft_putendl_nbr(tab[p_id].size.x);//
		ft_putstr("c : ");//
		ft_putendl_nbr(c);//
		while ((tab[p_id].size.x + c) <= m_size)
		{
<<<<<<< HEAD
<<<<<<< HEAD
			ft_putendl("let's take the map into 64");
			ft_print_bytes(&map[l], 2);
			ft_putendl("debug1");
			ft_print_bytes(map64, 32);
			ft_putendl("debug2");
//			ft_memcpy(map64, &map[l], 32);
//			ft_putendl("debug3");
			*map64 = (uint64_t)&map[l];
			ft_putstr("map has value : ");//
			ft_putendl_nbr(*map64);//
=======
=======
>>>>>>> 742a28ae616a68a5a94c46ca37ed1bb339a7c3dc
			ft_putendl("let's take 4 lines of the map into 64");//
			ft_print_bytes(&map[l], 8, 2);//
			//ft_putendl("map64 before");//
			// ft_print_bytes(map64, sizeof(map64), 2);//
			map64 = (uint64_t *)(map + l);
			// ft_putendl("map64 after");//
			// ft_print_bytes(map64, sizeof(map64), 2);//
<<<<<<< HEAD
>>>>>>> 742a28ae616a68a5a94c46ca37ed1bb339a7c3dc
=======
>>>>>>> 742a28ae616a68a5a94c46ca37ed1bb339a7c3dc
			if (((tab[p_id].movbin << c) & *map64) == 0)
			{
				ft_putstr("we can put the piece down. \nentree dans le test de recursivite n°");//
				ft_putendl_nbr(compteur);//
				ft_putendl("before putpiece map has value : ");//
				ft_print_bytes(map64, sizeof(map64), 2);//
				tab[p_id].pos.x = c;
				tab[p_id].pos.y = l;
				ft_putstr("we can put the piece down. at x  ");//
				ft_putnbr(c);//
				ft_putstr(" y ");//
				ft_putendl_nbr(l);//
				ft_putpiece(tab, p_id, map);
				//map64 = &map[l];
				ft_putendl("after putpiece map has value : ");//
				ft_print_bytes(map64, sizeof(map64), 2);// the map64 is 8 bytes long by the way
				if (ft_put64piece(tab, p_id + 1, map, m_size, p_qty, compteur + 1))
					return (1);
				else
				{
					ft_putstr("sortie de recursivite n° ");//
					ft_putendl_nbr(compteur);//
					ft_putstr("remove piece ");//
					ft_putendl_nbr(p_id);//
					ft_removepiece(tab, p_id, map);
					c++;
				}
			}
			
			ft_putendl_nbr(compteur);//
			c++;
		}
		l++;
	}
	return (0);
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

int		ft_piececanbeput(t_piece *tab, int p_id, uint16_t *map, int m_size)
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
				return (1);
			else if ((((0b1111 << mask * 4) & tab[p_id].compbin)
			<< tab[p_id].pos.x) & map[tab[p_id].pos.y + mask])
			{
				tab[p_id].pos.x++;
				mask = 0;
				break ;
			}
		tab[p_id].pos.x = 0;
	}
	tab[p_id].pos.x = 0;
	tab[p_id].pos.y = 0;
	return (0);
}

/*
** Put each line one by one at position shifted by column and line as passed
** Adding the bits on the line is made with OR
*/

void	ft_putpiece(t_piece *tab, int p_id, uint16_t *map)
{
	int	mask;

	mask = 0;
	while (mask < 4)
	{//
		// ft_putnbr(tab[p_id].pos.y + mask);
		// ft_putstr(" line is : ");//
		// ft_putendl_nbr(map[tab[p_id].pos.y + mask]);//
		// ft_putstr("number is : ");//
		// ft_print_bytes(&tab[p_id].compbin, 2, 0);//
		// ft_putendl("");//
		// ft_putstr("for this line, number part is : ");//
		// ft_print_bits(((0b1111 << (mask * 4)) & tab[p_id].compbin) >> (mask * 4) << tab[p_id].pos.x);//
		// ft_putendl("");//
		map[tab[p_id].pos.y + mask] = map[tab[p_id].pos.y + mask]
		+ (((0b1111 << (mask * 4)) & tab[p_id].compbin) >> (mask * 4) << tab[p_id].pos.x);
		// ft_putstr("line is now:");//
		// ft_putendl_nbr(map[tab[p_id].pos.y + mask]);//
		mask++;
	}//
}

/*
** Remove each line one by one at position shifted by column and line as passed
** Removing the bits on the line is made with XOR
*/

void	ft_removepiece(t_piece *tab, int p_id, uint16_t *map)
{
	int	mask;
	ft_putendl("map before removal : ");//
	ft_print_bytes(map, 32, 2);//
	ft_putendl("");
	mask = 0;
	while (mask < 4)
	{
		map[tab[p_id].pos.y + mask] = map[tab[p_id].pos.y + mask]
		^ (((0b1111 << (mask * 4)) & tab[p_id].compbin) >> (mask * 4) << tab[p_id].pos.x);
		mask++;
	}
	tab[p_id].pos.x = 0;
	tab[p_id].pos.y = 0;
	ft_putendl("map after removal : ");//
	ft_print_bytes(map, 32, 2);//
	ft_putendl("");
}

/*
** We try and place the piece
** if the piece can be put, we have a pos x y not -1
** and we put the piece at the saved x and y
** If all pieces won't fit, we increase the map size and start anew at piece 0
** If at end of max map size no result, we start anew BUT we shift first piece
*/

// int			ft_placer(t_piece *tab, int p_qty, size_t m_size, uint16_t *map)
// {
// 	ft_putendl("entree dans ft_placer :");//
// 	return (ft_put64piece(tab, 0, map, m_size, p_qty, 0));
// }

/*
** We take the map, and put the pieces inside
*/

uint16_t	*ft_mapbuilder(t_piece *tab, int p_qty, uint16_t *map)
{
	int	m_size;
	int compteur;//

	//ft_putendl("\ncalcul m_size min :");//
	m_size = 2;
	while (m_size * m_size < 4 * p_qty)
		m_size++;
	ft_putstr("initial map size : ");
	ft_putendl_nbr(m_size);//
	compteur = 0;
	ft_putstr("try : ");//
	ft_putendl_nbr(compteur);//
	while (!(ft_put64piece(tab, compteur, map, m_size, p_qty, 0)) && m_size <= 16)
	{
		ft_putendl("remise a zero de la map");//
		ft_bzero(map, sizeof(*map) * 16);
		ft_putstr("new map size:");
		ft_putendl_nbr(m_size + 1);//
		compteur++;
		m_size++;
	}
	ft_putendl("impression de la map");//
	ft_printmap(tab, m_size, p_qty);
	return (map);
}
