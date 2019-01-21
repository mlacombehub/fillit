/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:00:02 by mlacombe          #+#    #+#             */
/*   Updated: 2018/12/14 13:54:24 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	len;

	if (!s || !f)
		return (NULL);
	if (!(new_s = (char *)malloc(sizeof(*new_s) * (ft_strlen(s) + 1))))
		return (NULL);
	len = 0;
	while (s[len])
	{
		new_s[len] = f(len, s[len]);
		len++;
	}
	new_s[len] = 0;
	return (new_s);
}
