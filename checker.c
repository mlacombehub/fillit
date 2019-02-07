/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 19:43:53 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/07 19:50:49 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/includes/libft.h"

int		ft_verification(char *buff)
{
	unsigned short int	i;
	int					n_conn;

	n_conn = 0;
	i = 0;
	while (i++ < 20)
	{
		if (buff[i] == '#')
		{
			if (i + 1 < 20 && buff[i + 1] == '#')
				n_conn++;
			if (i - 1 < 20 && buff[i - 1] == '#')
				n_conn++;
			if (i + 5 < 20 && buff[i + 5] == '#')
				n_conn++;
			if (i - 5 < 20 && buff[i - 5] == '#')
				n_conn++;
		}
	}
	ft_putnbr(n_conn);
	return ((n_conn == 6 || n_conn == 8) ? 1 : 0);
}

/*
** Function preprocessing all the file in search of an error of
** typing/overwriting
*/

int		ft_checkfeed(char *feed, int feedsize)
{
	int	k;
	int hcount;

	if (feedsize / 21 < 1 || (feedsize) / 21 > 27 || feedsize % 21 != 0)
		return (0);
	while (*feed)
	{
		k = 0;
		hcount = 0;
		while (k < 20)
		{
			if (((k + 1) % 5 == 0 && feed[k] != '\n') || hcount > 4
				|| ((k + 1) % 5 != 0 && feed[k] != '#' && feed[k] != '.'))
				return (0);
			if (feed[k] == '#')
				hcount++;
			k++;
		}
		if ((feed[k] != '\n') || (!ft_verification(feed)))
			return (0);
		feed += 21;
	}
	return (1);
}

int		ft_puterror(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (0);
}
