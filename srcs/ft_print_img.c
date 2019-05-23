/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:53:02 by flhember          #+#    #+#             */
/*   Updated: 2019/05/23 14:42:47 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_set_z_line(t_env **data, int x, int y)
{
	(*data)->pts.z1 = (*data)->map.tab[y - 1][x - 1];
	if ((*data)->pts.z1 > 0)
		(*data)->pts.z1 += (*data)->zincr;
	(*data)->pts.z2 = (*data)->map.tab[y - 1][x];
	if ((*data)->pts.z2 > 0)
		(*data)->pts.z2 += (*data)->zincr;
	(*data)->pts.colorz1 = (*data)->pts.z1;
	(*data)->pts.colorz2 = (*data)->pts.z2;
}

static int	ft_filling_img_line(t_env **data, int x, int y)
{
	y = 1;
	while (y <= (*data)->map.size_col)
	{
		x = 1;
		(*data)->pts.y2 = y * (*data)->pad;
		(*data)->pts.y1 = y * (*data)->pad;
		(*data)->pts.x1 = x * (*data)->pad;
		(*data)->pts.x2 = (x + 1) * (*data)->pad;
		while (x + 1 <= (*data)->map.size_line)
		{
			ft_set_z_line(data, x, y);
			ft_rotation_x_y_z(data);
			if ((*data)->iso)
				iso(data, (*data)->pts.z1, (*data)->pts.z2);
			ft_bresenham(data, (*data)->pts.colorz1, (*data)->pts.colorz2, 0);
			x++;
			(*data)->pts.x1 = x * (*data)->pad;
			(*data)->pts.x2 = (x + 1) * (*data)->pad;
			(*data)->pts.y1 = y * (*data)->pad;
			(*data)->pts.y2 = y * (*data)->pad;
		}
		y++;
	}
	return (0);
}

static void	ft_set_z_col(t_env **data, int x, int y)
{
	(*data)->pts.z1 = (*data)->map.tab[y - 1][x - 1];
	if ((*data)->pts.z1 > 0)
		(*data)->pts.z1 += (*data)->zincr;
	(*data)->pts.z2 = (*data)->map.tab[y][x - 1];
	if ((*data)->pts.z2 > 0)
		(*data)->pts.z2 += (*data)->zincr;
	(*data)->pts.colorz1 = (*data)->pts.z1;
	(*data)->pts.colorz2 = (*data)->pts.z2;
}

static int	ft_filling_img_col(t_env **data, int x, int y)
{
	x = 1;
	while (x <= (*data)->map.size_line)
	{
		y = 1;
		(*data)->pts.x2 = x * (*data)->pad;
		(*data)->pts.x1 = x * (*data)->pad;
		(*data)->pts.y1 = y * (*data)->pad;
		(*data)->pts.y2 = (y + 1) * (*data)->pad;
		while (y + 1 <= (*data)->map.size_col)
		{
			ft_set_z_col(data, x, y);
			ft_rotation_x_y_z(data);
			if ((*data)->iso)
				iso(data, (*data)->pts.z1, (*data)->pts.z2);
			ft_bresenham(data, (*data)->pts.colorz1, (*data)->pts.colorz2, 0);
			y++;
			(*data)->pts.y1 = y * (*data)->pad;
			(*data)->pts.y2 = (y + 1) * (*data)->pad;
			(*data)->pts.x2 = x * (*data)->pad;
			(*data)->pts.x1 = x * (*data)->pad;
		}
		x++;
	}
	return (0);
}

void		ft_print_img(t_env **data)
{
	(*data)->img_ptr = mlx_new_image((*data)->mlx_ptr, 1920, 1080);
	(*data)->img_str = (unsigned char*)mlx_get_data_addr((*data)->img_ptr,
			&(*data)->bpp, &(*data)->s_l, &(*data)->endian);
	ft_filling_img_line(data, 0, 0);
	ft_filling_img_col(data, 0, 0);
	mlx_put_image_to_window((*data)->mlx_ptr,
			(*data)->win_ptr, (*data)->img_ptr, 0, 0);
	ft_print_control(data);
}
