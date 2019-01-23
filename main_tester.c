/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:35:44 by xbarthe           #+#    #+#             */
/*   Updated: 2019/01/23 23:22:21 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#define CHAR_AS_BIT '#'

int     ft_revCharToBit(char *c, char b);
int     ft_charToBit(char *c, char b);

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *c;
        c = argv[1];
        ft_putnbr(ft_charToBit(c, CHAR_AS_BIT));
    }
    else
    {
        ft_putstr("usage : executable string_with_the_bit_as_a_given_char (where the char is '");
        ft_putchar(CHAR_AS_BIT);
        ft_putendl("')");
    }
}