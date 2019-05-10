/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:42:52 by flhember          #+#    #+#             */
/*   Updated: 2019/05/09 17:42:54 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*void	ft_printf_tabmap(t_mapy **map)
{
	int	i = 0;
	int	j;
	while (i < (*map)->size_col)
	{
		j = 0;
		while (j < (*map)->size_line)
			printf("%d ", (*map)->tab[i][j++]);
		printf("\n");
		i++;
	}
}*/

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
	ft_free(&data, 1);
	return (0);
}
