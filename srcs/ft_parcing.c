/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:13:39 by flhember          #+#    #+#             */
/*   Updated: 2019/05/23 15:21:47 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	**ft_realloc_map(t_env **data, int i, int j)
{
	int		**new_tab;

	i = 0;
	new_tab = NULL;
	if (!(new_tab = (int**)ft_memalloc(sizeof(int*)
					* ((*data)->map.size_col + 1))))
		return (NULL);
	while (i < (*data)->map.size_col)
	{
		if (!(new_tab[i] = (int*)ft_memalloc(sizeof(int)
						* ((*data)->map.size_line))))
			return (NULL);
		j = 0;
		while (j < (*data)->map.size_line)
		{
			new_tab[i][j] = (*data)->map.tab[i][j];
			j++;
		}
		i++;
	}
	if (!(new_tab[i] = (int*)ft_memalloc(sizeof(int)
					* ((*data)->map.size_line))))
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
		if (str[i] == ' ' && str[i + 1] != '\0')
		{
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
				nb++;
		}
		i++;
	}
	if (!((*data)->map.tab = (int**)ft_memalloc(sizeof(int*) * 1)))
		return (-1);
	if (!((*data)->map.tab[0] = (int*)ft_memalloc(sizeof(int) * nb)))
		return (-1);
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
	if (j < (*data)->map.size_line)
		return (0);
	return (1);
}

static int	ft_read_file(t_env **data, int i, int res, char *tmp)
{
	tmp = NULL;
	while (res == 1)
	{
		res = get_next_line((*data)->fd, &tmp);
		if (res == 1)
		{
			if ((*data)->map.tab == NULL)
				(*data)->map.size_line = ft_alloc_tab(tmp, data);
			else
				(*data)->map.tab = ft_realloc_map(data, 0, 0);
			(*data)->map.size_col++;
			if ((*data)->map.size_line <= 0 || !(*data)->map.tab
					|| !(ft_filling_tab(data, tmp, i)))
			{
				tmp ? ft_strdel(&tmp) : tmp;
				return (0);
			}
			i++;
		}
		tmp ? ft_strdel(&tmp) : tmp;
	}
	if (res == 0 && i == 0)
		return (0);
	return (1);
}

int			ft_parcing(t_env **data, char *file)
{
	int		res;

	res = 1;
	if (((*data)->fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Open fail\n", 2);
		return (0);
	}
	if (!(ft_read_file(data, 0, res, NULL)))
	{
		if (!(*data)->map.size_line)
			ft_putstr_fd("Usage : Map Error\n", 2);
		else if ((*data)->map.size_line == -1 || !(*data)->map.tab)
			ft_putstr_fd("Malloc Error\n", 2);
		else
			ft_putstr_fd("Usage : Map Error\n", 2);
		ft_free(data, 1);
		close((*data)->fd);
		return (0);
	}
	close((*data)->fd);
	return (1);
}
