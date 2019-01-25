/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:22:23 by mlacombe          #+#    #+#             */
/*   Updated: 2019/01/25 18:03:15 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char			*map[FILE_LENGTH + 1];
	int				fd;
	int				originmap;
	int				binmap;
	int				finalmap;

	if (argc == 2)
		if (fd == open(argv[1], O_RDONLY))
		{
			originmap = read(fd, map, FILE_LENGTH);
			map[FILE_LENGTH + 1] = '\0';
			binmap = ft_checking(originmap, map);
			finalmap = ft_print_map(binmap);
			close(originmap);
		}
		else
			ft_putendl_fd(2, "error");
	else
		ft_putendl_fd(2, "usage: ./fillit [input_file]");
	return (0);
}

int		ft_checking(int originmap, char *map)
{
	char		buff[22];
	char		checker;
	int			binmap;
	t_piece		piece;

	*piece.n_piece = 'A';
	while (originmap != *piece.n_piece++ * 21)
	{
		*buff = originmap + (*piece.n_piece - 1) * 21;
		checker = buff[0];
		if ((buff[4] && buff[9] && buff[14] && buff[19] && buff[20]) == '\n' && piece.n_piece <= 27)
		{
			while (checker++ != buff[20])
				if (checker != '#' || checker != '.' || checker != '\n')
					return (0);
			piece = ft_piece_creator(buff, piece.n_piece);
			//map[(*piece.n_piece - 1) * 20] = ft_char_to_bin(*buff, piece);
		}
		else if (buff[0] == '\0')
			return (binmap = *map);
		else
			return (0);
	}
	free(map);
}

int		ft_char_to_bin(char *buff, t_piece piece)
{
	int		i;
	char	*ret;

	i = 1;
	while (buff[i++] != '\0')
	{
		if (!(buff = ft_verification(buff)))
			return (0);
		piece.binary = ft_buff_to_binary(buff);
	}
	return (ret);
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

uint16_t		*ft_buff_to_binary(char *buff)
{
	size_t	i;
	size_t	j;
	char	binmap[16];

	i = 19;
	j = 16;
	while (i--)
		if (buff[i] == '#')
			binmap[j--] = 1;
		else if (buff[i] == '.')
			binmap[j--] = 0;
	// while ((binmap[15] && binmap[14] && binmap[13] && binmap[12]) == 0)
	// {
	// 	binmap[15] << 16;
	// 	binmap[14] << 15;
	// 	binmap[13] << 14;
	// 	binmap[12] << 13;
	// }
	// while ((binmap[15] && binmap[11] && binmap[7] && binmap[3]) == 0)
	// 	(binmap[15] && binmap[11] && binmap[7] && binmap[3]) << 4;
	return (binmap);
}

t_piece	ft_piece_creator(char *buff, char letter)
{
	t_piece	piece;
	int i;

	i = 0;
	piece.n_piece = letter;
	piece.width = 1;
	piece.height = 1;
	while (buff[i++])
	{
		if ((buff[i] == buff[i + 1]) && buff[i] != '.')
			piece.width++;
		else if ((buff[i] == buff [i + 5]) && buff[i] != '.')
			piece.height++;
	}
	return (piece);
}

int		ft_print_map()
{

}
