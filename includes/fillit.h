/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:20 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/11 16:50:18 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_MAX_LENGTH (26 * 21)

# include <fcntl.h>
# include "../libft/includes/libft.h"

/*
** n_piece : the printed char (order of reading a b c ...)
**
*/

typedef struct	s_piece
{
	int			num_piece;
	int			origpos;
	int			width;
	int			height;
	uint16_t	compbin;
	uint16_t	refbin;
	uint64_t	movbin;
	char 		tetchar[22];
}				t_piece;

// remove this
/*
typedef	struct s_map
{
	uint16_t	mappart[16];
	char		mapinletters[256];
}				t_map;
*/

/*
** checker.c functions
*/

int				ft_verification(char *buff);
int				ft_checkfeed(char *feed, int feedsize);

/*
** slicer.c functions
*/

uint16_t		ft_rev_chartobit(char *c, char thebitchar);
int				ft_bitcompact(int bitmino, int sidesize);
int				ft_measurewidth(uint16_t stuff, size_t s);
int				ft_measureheight(uint16_t stuff, size_t s);
void			ft_feedtopieces(t_piece *tab, char *feed);


/*
** solver.c functions
*/

void ft_backtrack(t_piece *tab, int pieceqty, t_map *map );

/*
** utilities.c functions (for debug)
*/

void    		ft_printmino(int mino, int sidesize);

#endif
