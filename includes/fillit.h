/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:20 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 18:00:09 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_MAX_LENGTH (546)

# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

/*
** a struct representing the piece's various elements
** p_id : the piece letter 0 + 'A'
** pos : position where we put the pice on the map
** size : w and h of the piece
** compbin : mino compacted up to left
** refbin : initial piece put into bin
** movbin : the piece exploded over 64 bits
** tetchar : the piece as char as received
*/

typedef struct	s_piece
{
	int			p_id;
	int			islast;
	t_point		pos;
	t_point		size;
	uint16_t	compbin;
	uint64_t	movbin;
	char		tetchar[22];
}				t_piece;

/*
** checker.c functions
*/

int				ft_checkfeed(char *feed, int feedsize);

/*
** slicer.c functions
** TODO remove one function, too long
*/

void			ft_feedtopieces(t_piece *tab, char *feed);

/*
** solver.c functions
*/

int				ft_mapbuilder(t_piece *tab, int p_qty, uint16_t *map);
#endif
