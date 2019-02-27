/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:20 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/27 15:44:44 by mlacombe         ###   ########.fr       */
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
	char			tetchar[22];
	uint64_t		movbin;
	uint16_t		compbin;
	t_point			pos;
	t_point			size;
	unsigned short	islast;
	unsigned short	p_id;
}				t_piece;

/*
** checker.c functions
*/

int				ft_checkfeed(char *feed, size_t feedsize);

/*
** slicer.c functions
** TODO remove one function, too long
*/

void			ft_feedtopieces(t_piece *tab, char *feed);

/*
** solver.c functions
*/

int				ft_mapbuilder(t_piece *tab, unsigned short p_qty
				, uint16_t *map);
#endif
