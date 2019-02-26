/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:00:02 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 19:19:58 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
