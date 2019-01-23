/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:20 by mlacombe          #+#    #+#             */
/*   Updated: 2019/01/21 15:36:26 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_LENGTH (26 * 21 + 1)

# include "../libft/includes/libft.h"

typedef struct	s_map
{
	unsigned short int	l0: 4;
	unsigned short int	l1: 4;
	unsigned short int	l2: 4;
	unsigned short int	l3: 4;
}				t_map;

typedef struct	s_piece
{
	size_t	n_piece;
	char	binary;
}				t_piece;

#endif