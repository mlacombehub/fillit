/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:59:47 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 19:10:05 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strctrim(const char *s, char c)
{
	size_t	end;
	size_t	start;

	end = ft_strlen(s) - 1;
	start = 0;
	while (s[start] && s[start] == c)
		start++;
	if (s[start] == 0)
		return (ft_strdup(s + start));
	while (end > 0 && s[end] == c && s[end])
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
