/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:29:27 by mlacombe          #+#    #+#             */
/*   Updated: 2018/12/05 12:59:23 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	end;
	size_t	start;

	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	start = 0;
	while (s[start] && ft_isspace(s[start]))
		start++;
	if (s[start] == 0)
		return (ft_strdup(s + start));
	while (end > 0 && ft_isspace(s[end]))
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
