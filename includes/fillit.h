/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:20 by mlacombe          #+#    #+#             */
/*   Updated: 2019/01/25 18:52:15 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_LENGTH (26 * 21 + 1)

# include "../libft/includes/libft.h"

typedef struct	s_piece
{
	char		*n_piece;
	int			oposition;
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