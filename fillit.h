/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:20 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/07 16:31:48 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_MAX_LENGTH (26 * 21)

# include "../libft/includes/libft.h"

/*
** n_piece : the printed char (order of reading a b c ...)
**
*/


typedef struct	s_piece
{
	int			num_piece;
	char 		*tetriminchar[22];
	int			origposition;
	int			width;
	int			height;
	uint16_t	referencebinary;
	uint64_t	movedbinary;
}				t_piece;

typedef	struct s_map
{
	uint16_t	mappart[4];
	char		mapinletters[256];
}				t_map;

#endif
