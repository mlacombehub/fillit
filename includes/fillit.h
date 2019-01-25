/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:20 by mlacombe          #+#    #+#             */
/*   Updated: 2019/01/25 14:50:36 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_LENGTH (26 * 21 + 1)

# include "../libft/includes/libft.h"
// faudra revoir cette struct voire la supprimer

typedef struct	s_piece
{
	char		*n_piece;
	int			oposition;
	int			width;
	int			height;
	uint16_t	binary;
}				t_piece;

#endif