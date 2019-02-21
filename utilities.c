/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:39:57 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/21 14:02:59 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/fillit.h"

/*
 ** takes an int and print it out as square
 ** do a >> shift of squareside and set above squareside to 0
 ** bit masking to set the bigger bit above squareSide to 0
 ** complement by 0s if the number is missing left 0s
 */

void	ft_printmino(int mino, int sidesize)
{
	int newmino;
	int k;

	newmino = mino;
	k = 0;
	while (newmino > 0)
	{
		k++;
		if (k != 0 && k % (sidesize + 1) == 0)
		{
		}
		else
		{
			newmino = newmino >> 1;
		}
	}
}

void	ft_printmap(t_piece *tab, int m_size, int p_qty)
{
	char	map[m_size * (m_size + 1)];
	int		k;

	k = m_size * (m_size + 1);
	map[k - 1] = '\0';
	while (--k >= 1)
	{
		if (k % (m_size + 1) == 0 && k != 0)
			map[k - 1] = '\n';
		else
			map[k - 1] = '.';
	}
	while (--p_qty >= 0)
	{
		while (k < 16)
		{
			if ((tab[p_qty].compbin & (0b1 << k)) != 0)
			{
				map[((tab[p_qty].pos.y + k / 4) * (m_size + 1))
				+ (tab[p_qty].pos.x + k % 4)] = p_qty + 'A';
			}
			k++;
		}
		k = 0;
	}
	ft_putendl(map);
}

/*
** prints the bytes from memory reversed
** we print from the [ptr] address, [size] bytes grouping by [step]
** prefixing with grouping number
** if step is 0 we juste print separated by space
*/

void	ft_print_bytes(void *ptr, int size, int step)
{
	unsigned char	*p;
	int				i;

	p = ptr;
	if (ptr)
	{
		i = 0;
		while (i < size)
		{
			if (step != 0 && i % step == 0)
			{
				ft_putnbr(i / step);
				ft_putstr("\t");
			}
			ft_print_bits(ft_reversed_bits(p[i]));
			ft_putstr(" ");
			i++;
			if (step != 0 && i % step == 0)
				ft_putstr("\n");
		}
	}
	else
		ft_putstr("[NULL pointer]");
	ft_putstr("\n");
}
