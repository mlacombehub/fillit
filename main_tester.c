/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:35:44 by xbarthe           #+#    #+#             */
/*   Updated: 2019/01/24 14:08:46 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#define CHAR_AS_BIT '#'
#define FT_BIG_ENDIAN 0

/*
** to compile as "gcc FLAGS srcs/ft_bitwise.c libft/libft.a main_tester.c"
*/

int     ft_chartobit(char *c, char b, int bigEnd);
int     ft_right_chartobit(char *c, char b);
int     ft_rev_chartobit(char *c, char b);

int     main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *c;
        c = argv[1];
        ft_putendl("big endian:");
        ft_putnbr(ft_chartobit(c, CHAR_AS_BIT, FT_BIG_ENDIAN));
        ft_putendl("\nrev:");
        ft_putnbr(ft_rev_chartobit(c, CHAR_AS_BIT));
        ft_putendl("\nright:");
        ft_putnbr(ft_right_chartobit(c, CHAR_AS_BIT));
    }
    else
    {
        ft_putstr("usage : executable string_with_the_bit_as_a_given_char (where the char is '");
        ft_putchar(CHAR_AS_BIT);
        ft_putendl("')");
    }
}
