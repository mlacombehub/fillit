/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:22:23 by mlacombe          #+#    #+#             */
/*   Updated: 2019/01/21 16:56:36 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
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
			finalmap = ft_print_map(binmap);
			close (originmap);
		}
		else
			ft_putendl_fd(2,"error");
	else
		ft_putendl_fd(2, "usage: ./fillit [source_file]");
	return (0);
}

int		ft_checking(int originmap, char *map)
{
	char		buff[20];
	char		checker;
	size_t		n_piece;
	int			binmap;

	n_piece = 1;
	while (originmap != n_piece++ * 21)
	{	
		*buff = originmap + (n_piece - 1) * 21;
		checker = buff[0];
		if((buff[4] && buff[9] && buff[14] && buff[19] && buff[20]) == '\n' && n_piece <= 27)
		{
			while (checker++ != buff[20])
				if (checker != '#' || checker != '.' || checker != '\n')
					return (0);
			map[(n_piece - 1) * 20] = ft_char_to_bin(*buff, n_piece);
		}
		else if (buff[0] == '\0')
			return(binmap = *map);
		else
			return (0);
	}
	free (map);
}

int		ft_char_to_bin(char *buff, size_t n_piece)
{
	int		i;
	char	*ret;
	t_piece	*piece;

	i = 1;
	while (buff[i++] != '\0')
	{
		if (!(n_piece = ft_verification(buff)))
			return (0);
		piece = ft_buff_to_map(buff);
	}
	ft_strcpy(ret, buff);
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

t_piece		*ft_buff_to_piece(char *buff)
{
	t_piece	*piece;
	size_t		i;
	int			j;
	uint16_t	binmap;

	i = 19;
	binmap = NULL;
	while (i--)
	{
		if (buff[i] = '#')
			binmap = 1;
		else if (buff[i] = '.')
			binmap = 0;
		binmap << 1;
	}
	while (xxxxxxx)
	{
		if ((buff[i - 2] && buff[i - 3] && buff[i - 4] && buff[i - 5]) == 0)
			;
	}
	piece->binary = binmap;
	return (piece);
}

char	ft_solve()
{

}

int		ft_print_map()
{

}