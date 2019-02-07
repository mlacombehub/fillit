/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:15:30 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/07 19:45:09 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "checker.c"

/*
t_piece		*ft_feedtopieces(char *feed)
{
	t_piece 	*tabpieces;
	int 		k;

	while (*feed)
	{
		tabpieces[k].tetriminchar = ft_strsub(feed, 0, 21);
		tabpieces[k].width = ;
		tabpieces[k].width = ;
		feed += 21;
		k++;
	}

}
*/
int		main(int argc, char **argv)
{
	int				fd;
	int				feedsize;
	char			feed[FILE_MAX_LENGTH + 1];

	if (argc != 2)
		return (ft_puterror("usage: ./fillit [input_file]"));
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		return (ft_puterror("error"));
	feedsize = read(fd, feed, FILE_MAX_LENGTH);
	feed[feedsize] = '\0';
	if (ft_checkfeed(feed, feedsize) == 0)
		return (ft_puterror("error"));
	return (0);
}
