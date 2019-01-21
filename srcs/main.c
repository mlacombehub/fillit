/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:22:23 by mlacombe          #+#    #+#             */
/*   Updated: 2019/01/13 14:22:25 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*map[FILE_LENGTH + 1];
	int		fd;
	int		originmap;
	int		binmap;
	int		finalmap;

	if (argc == 2)
		if (fd = open(argv[1], O_RDONLY))
		{
			originmap = read(fd, map, FILE_LENGTH);
			map[FILE_LENGTH + 1] = '\0';
			binmap = ft_checking(originmap, map);
			finalmap = print_map(binmap);
			close (originmap);
		}
		else
			ft_putendl_fd(2,"error");
	else
		ft_putendl_fd(2, "usage: ./fillit [source_file]");
	return (0);
}

int		ft_checking(int origin, char *map)
{
	;
}

int		ft_testchecking(int origin, char *map)
{
	char		buff[22];
	char		checker;
	size_t		n_piece;
	int			map;

	n_piece = 0;
//	while (buff == (read(fd, piece, 21)))
	{
		checker = buff[0];
		if((buff[5] && buff[10] && buff[15] && buff[20]) == '\n' && (buff[21] == ('\n' || '\0')) && n_piece <= FILE_LENGTH)
		{
			while (checker++ != buff[22])
				if (checker != '#' || checker != '.' || checker != '\n')
					return (0);
			map = ft_checker(*buff, n_piece);
			n_piece++;
		}
		else
			return (0);
		n_piece++;
	}
}

int		ft_checker(char *buff, size_t n_piece)
{
	int	i;

	i = 1;
	while (buff[i++] != '\0')
		return ((buff[i - 1] != '\n' && (buff[i - 1] != '#' && buff[i - 1] != '.') && (buff[i - 1] != '#')) ? 1 : 0);
	return (((buff[i] != '\0') || !(n_piece = ft_verification(buff))) ? 1 : 0);
}

int		ft_verification(char *buff)
{
	unsigned short int	i;
	int					n_conn;

	n_conn = 0;
	i = 0;
	while (i++ < 20)
	{
		if (buff[i] == '#')
		{
			if (i + 1 < 20 && buff[i + 1] == '#')
				n_conn++;
			if (i - 1 < 20 && buff[i - 1] == '#')
				n_conn++;
			if (i + 5 < 20 && buff[i + 5] == '#')
				n_conn++;
			if (i - 5 < 20 && buff[i - 5] == '#')
				n_conn++;
		}
	}
	return ((n_conn == 6 || n_conn == 8) ? 1 : 0);
}

t_piece		ft_buff_to_piece(char *buff)
{
	t_piece	piece;
	int		i;
	int		j;

	i = 19;
	while (i)
	{
		if (buff[i] = '#')
			buff[i] = 1;
		else if (buff[i] = '.')
			buff[i] = 0;
		i--;
		if (i % 5 == 4)
		{
			j = i + 4;
			while (j < 5)
				piece.l0 = buff[j--];
			while (5 <= j && j <= 10)
				piece.l1 = buff[j--];
			while (11 <= j && j <= 15)
				piece.l2 = buff[j--];
			while (16 <= j && j < 20)
				piece.l3 = buff[j--];
		}
	}
	return (piece);
}

char	ft_solve()
{

}

int		ft_print_map()
{

}