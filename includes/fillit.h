/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:20 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/08 12:12:38 by xbarthe          ###   ########.fr       */
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
	int			origposition;
	int			width;
	int			height;
	uint16_t	referencebinary;
	uint64_t	movedbinary;
	char 		tetriminchar[22];
}				t_piece;

typedef	struct s_map
{
	uint16_t	mappart[4];
	char		mapinletters[256];
}				t_map;

int		ft_verification(char *buff);
int		ft_checkfeed(char *feed, int feedsize);

#endif
