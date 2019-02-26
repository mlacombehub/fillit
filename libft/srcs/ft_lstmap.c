/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacombe <mlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:37:14 by mlacombe          #+#    #+#             */
/*   Updated: 2019/02/26 14:55:12 by mlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if (lst != NULL)
	{
		if (!(new_lst = (t_list *)malloc(sizeof(*new_lst) + 1)))
		{
			free(new_lst);
			return (NULL);
		}
		new_lst = f(lst);
		if (!(new_lst->next = ft_lstmap(lst->next, f)))
		{
			free(new_lst);
			return (NULL);
		}
	}
	return (NULL);
}
