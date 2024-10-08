/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:15:30 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/27 15:44:28 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** removed the dynamic size of the printed map, replaced by a parameter
** before we had m_size * (m_size +1) instead of size
*/

static void	ft_printmap(t_piece *tab, int m_size, int p_qty, int size)
{
	char				map[size];
	unsigned short		k;

	k = m_size * (m_size + 1);
	map[k - 1] = '\0';
	while (--k >= 1)
		map[k - 1] = ((k % (m_size + 1) == 0 && k != 0) ? '\n' : '.');
	while (--p_qty >= 0)
	{
		while (k < 16)
		{
			if ((tab[p_qty].compbin & (0b1 << k)) != 0)
				map[((tab[p_qty].pos.y + k / 4) * (m_size + 1))
				+ (tab[p_qty].pos.x + k % 4)] = p_qty + 'A';
			k++;
		}
		k = 0;
	}
	ft_putendl(map);
}

/*
** no malloc, creates a table for the tetriminos
*/

int			main(int argc, char **argv)
{
	unsigned short	fd;
	size_t			feedsize;
	t_piece			tab[26];
	char			feed[FILE_MAX_LENGTH];
	uint16_t		map[16];

	if (argc != 2)
		return (ft_puterror("usage: ./fillit [input_file]"));
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
	{
		ft_putendl("error");
		return (FALSE);
	}
	feedsize = read(fd, feed, FILE_MAX_LENGTH + 1);
	feed[feedsize] = '\0';
	if (ft_checkfeed(feed, feedsize) == 0)
	{
		ft_putendl("error");
		return (FALSE);
	}
	ft_feedtopieces(tab, feed);
	ft_printmap(tab, ft_mapbuilder(tab, (feedsize + 1) / 21, map),
	(feedsize + 1) / 21, (feedsize + 1) / 21 * ((feedsize + 1) / 21 + 1));
	return (FALSE);
}
