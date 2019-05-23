/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:42:52 by flhember          #+#    #+#             */
/*   Updated: 2019/05/23 16:28:13 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int arc, char **arv)
{
	t_env	*data;

	data = NULL;
	if (arc != 2)
	{
		ft_putstr_fd("Usage : ./fdf [1 source map]\n", 2);
		return (-1);
	}
	if (!(data = (t_env*)ft_memalloc(sizeof(t_env))))
		return (0);
	ft_fdf(&data, arv[1]);
	return (0);
}
