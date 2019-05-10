/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:40:05 by flhember          #+#    #+#             */
/*   Updated: 2019/05/09 17:08:54 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free(t_env **data, int flag)
{
	int		i;

	i = 0;
	if ((*data)->map.tab)
	{
		while (i < (*data)->map.size_col)
		{
			free((*data)->map.tab[i]);
			i++;
		}
		free((*data)->map.tab);
	}
	if (flag == 1)
		free(*data);
}
