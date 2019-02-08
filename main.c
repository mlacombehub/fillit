/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:15:30 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/08 13:02:20 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int		ft_puterror(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (0);
}

int		main(int argc, char **argv)
{
	int				fd;
	int				feedsize;
	t_piece 		tab[26];
	char			feed[FILE_MAX_LENGTH + 1];

	if (argc != 2)
		return (ft_puterror("usage: ./fillit [input_file]"));
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		return (ft_puterror("error"));
	feedsize = read(fd, feed, FILE_MAX_LENGTH + 1);
	feed[feedsize] = '\0';
	if (ft_checkfeed(feed, feedsize) == 0)
		return (ft_puterror("error"));
	ft_feedtopieces(tab, feed);
	return (0);
}
