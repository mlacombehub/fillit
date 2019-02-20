/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:20 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/20 20:38:01 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_MAX_LENGTH (26 * 21)

# include <fcntl.h>
# include "../libft/includes/libft.h"
# include <stdio.h> //

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
	t_point		pos;
	t_point		size;
	int			width;
	int			height;
	uint16_t	compbin;
	uint16_t	refbin;
	uint64_t	movbin;
	char		tetchar[22];
}				t_piece;

/*
** checker.c functions
*/

int				ft_verification(char *buff);
int				ft_checkfeed(char *feed, int feedsize);

/*
** slicer.c functions
** TODO remve one function, too long
*/

uint16_t		ft_rev_chartobit(char *c, char thebitchar);
int				ft_bitcompact(int bitmino, int sidesize);
int			ft_measure_width_height(uint16_t binsrc, int sizex,int sizey,
int sidesize);
void			ft_feedtopieces(t_piece *tab, char *feed);
uint64_t		ft_bit16to64(int compbit, int sidesize);

/*
** solver.c functions
*/

uint16_t		*ft_mapbuilder(t_piece *tab, int p_qty, uint16_t *map);
int				ft_piececanbeput(t_piece *tab, int p_id, uint16_t *map,
int m_size);
void			ft_putpiece(t_piece *tab, int p_id, uint16_t *map);
void			ft_removepiece(t_piece *tab, int p_id, uint16_t *map);
int				ft_put64piece(t_piece *tab, int p_id, uint16_t *map,
int m_size, int p_qty, int compteur);

/*
** utilities.c functions (for debug)
*/

void			ft_printmino(int mino, int sidesize);
void			ft_printmap(t_piece *piece, int m_size, int p_qty);
void			ft_print_bytes(void *ptr, int size, int step);
#endif
