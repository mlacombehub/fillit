/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 19:43:53 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/26 18:03:37 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function checking that the # have proper neighbours
** to build a legitimate tetrimino
** (we expect between 6 and 8 'connections' between # )
*/

static int		ft_verification(char *buff)
{
	unsigned short int	i;
	int					n_conn;

	n_conn = 0;
	i = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			if (i + 1 < 20 && buff[i + 1] == '#')
				n_conn++;
			if (i - 1 >= 0 && buff[i - 1] == '#')
				n_conn++;
			if (i + 5 < 20 && buff[i + 5] == '#')
				n_conn++;
			if (i - 5 >= 0 && buff[i - 5] == '#')
				n_conn++;
		}
		i++;
	}
	return ((n_conn == 6 || n_conn == 8) ? 1 : 0);
}

/*
** Function preprocessing all the file in search of an error of
** typing/overwriting
*/

int				ft_checkfeed(char *feed, int feedsize)
{
	int	k;
	int hcount;

	if ((feedsize + 1) / 21 <= 0 || (feedsize + 1) / 21 > 26
	|| (feedsize + 1) % 21 != 0)
		return (FALSE);
	while (*feed && feed)
	{
		k = 0;
		hcount = 0;
		while (k < 20)
		{
			if (((k + 1) % 5 == 0 && feed[k] != '\n') || hcount > 4
				|| ((k + 1) % 5 != 0 && feed[k] != '#' && feed[k] != '.'))
				return (FALSE);
			if (feed[k] == '#')
				hcount++;
			k++;
		}
		if (!ft_verification(feed))
			return (0);
		feed += 21;
	}
	return (TRUE);
}
