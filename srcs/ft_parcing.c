/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:13:39 by flhember          #+#    #+#             */
/*   Updated: 2019/05/10 18:07:50 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	**ft_realloc_map(t_env **data)
{
	int		i;
	int		j;
	int		**new_tab;

	i = 0;
	new_tab = NULL;
	if (!(new_tab = (int**)ft_memalloc(sizeof(int*) * ((*data)->map.size_col + 1))))
		return (NULL);
	while (i < (*data)->map.size_col)
	{
		if (!(new_tab[i] =
						(int*)ft_memalloc(sizeof(int) * ((*data)->map.size_line))))
			return (NULL);
		j = 0;
		while (j < (*data)->map.size_line)
		{
			new_tab[i][j] = (*data)->map.tab[i][j];
			j++;
		}
		i++;
	}
	if (!(new_tab[i] = (int*)ft_memalloc(sizeof(int) * ((*data)->map.size_line))))
		return (NULL);
	ft_free(data, 0);
	return (new_tab);
}

static int	ft_alloc_tab(char *str, t_env **data)
{
	int		i;
	int		nb;

	i = 0;
	nb = 1;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			nb++;
		}
		i++;
	}
	if (!((*data)->map.tab = (int**)ft_memalloc(sizeof(int*) * 1)))
		return (0);
	if (!((*data)->map.tab[0] = (int*)ft_memalloc(sizeof(int) * nb)))
		return (0);
	return (nb);
}

static int	ft_filling_tab(t_env **data, char *str, int i)
{
	int		j;
	int		res;
	int		cmp;

	j = 0;
	res = 0;
	cmp = 0;
	while (*str)
	{
		if (j >= (*data)->map.size_line)
			return (0);
		res = ft_atoi(str);
		while (*str && *str != ' ')
			str++;
		while (*str && *str == ' ')
			str++;
		(*data)->map.tab[i][j++] = res;
	}
	return (1);
}

static int	ft_read_file(int fd, t_env **data, int i, int res)
{
	char	*tmp;

	tmp = NULL;
	while (res == 1)
	{
		res = get_next_line(fd, &tmp);
		if (res == 1)
		{
			if ((*data)->map.tab == NULL)
				(*data)->map.size_line = ft_alloc_tab(tmp, data);
			else
				(*data)->map.tab = ft_realloc_map(data);
			if (!(ft_filling_tab(data, tmp, i)))
				return (0);
			i++;
			(*data)->map.size_col = i;
		}
		if (tmp)
			ft_strdel(&tmp);
	}
	return (1);
}

int		ft_parcing(t_env **data, char *file)
{
	int		i;
	int		fd;
	int		res;

	i = 0;
	fd = 0;
	res = 1;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Open fail\n", 2);
		return (0);
	}
	if (!(ft_read_file(fd, data, i, res)))
	{
		ft_putstr_fd("Usage : Map Error\n", 2);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
