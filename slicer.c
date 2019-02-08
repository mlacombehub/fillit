/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slicer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbarthe <xbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:10:53 by xbarthe           #+#    #+#             */
/*   Updated: 2019/02/08 12:16:23 by xbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_piece		*ft_feedtopieces(char *feed)
{
	t_piece 	*tabpieces;
	int 		k;

	while (*feed)
	{
		tabpieces[k].tetriminchar = ft_strsub(feed, 0, 21);
		tabpieces[k].width = ;
		tabpieces[k].width = ;
		feed += 21;
		k++;
	}

}

