/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:12:26 by flhember          #+#    #+#             */
/*   Updated: 2019/05/23 15:57:35 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_color(t_env **data, int i, int pixel)
{
	if (!i)
	{
		(*data)->img_str[pixel] = 0;
		(*data)->img_str[pixel + 1] = 0;
		(*data)->img_str[pixel + 2] = 255;
	}
	else
	{
		(*data)->img_str[pixel] = 0;
		(*data)->img_str[pixel + 1] = 255;
		(*data)->img_str[pixel + 2] = 0;
	}
}

static void	fill_pixel(t_env **data, int z1, int z2, int i)
{
	int pixel;

	pixel = (4 * (*data)->pts.tmpx) + (4 * 1920 * (*data)->pts.tmpy);
	if ((*data)->pts.tmpx > 0 && (*data)->pts.tmpy > 0
			&& (*data)->pts.tmpx < 1920 && (*data)->pts.tmpy < 1080
			&& pixel < ((1920 * 1080) * 4))
	{
		if (z1 > 0 && z2 > 0)
		{
			(*data)->img_str[pixel] = 0;
			(*data)->img_str[pixel + 1] = 0;
			(*data)->img_str[pixel + 2] = 255;
		}
		else if ((z1 > 0 && z2 == 0))
			ft_color(data, i, pixel);
		else
		{
			(*data)->img_str[pixel] = 0;
			(*data)->img_str[pixel + 1] = 255;
			(*data)->img_str[pixel + 2] = 0;
		}
	}
}

static void	ft_init(t_env **data)
{
	(*data)->pts.y1 += (*data)->margey;
	(*data)->pts.y2 += (*data)->margey;
	(*data)->pts.x1 += (*data)->margex;
	(*data)->pts.x2 += (*data)->margex;
	(*data)->pts.tmpx = (*data)->pts.x1;
	(*data)->pts.tmpy = (*data)->pts.y1;
	(*data)->pts.dx = (*data)->pts.x2 - (*data)->pts.x1;
	(*data)->pts.dy = (*data)->pts.y2 - (*data)->pts.y1;
	(*data)->pts.xincr = ((*data)->pts.dx > 0) ? 1 : -1;
	(*data)->pts.yincr = ((*data)->pts.dy > 0) ? 1 : -1;
	(*data)->pts.dx = abs((*data)->pts.dx);
	(*data)->pts.dy = abs((*data)->pts.dy);
}

static void	ft_bresenham_bis(t_env **data, int z1, int z2)
{
	int		cumul;
	int		i;

	i = 1;
	cumul = (*data)->pts.dy / 2;
	while (i++ <= (*data)->pts.dy)
	{
		(*data)->pts.tmpy += (*data)->pts.yincr;
		cumul += (*data)->pts.dx;
		if (cumul >= (*data)->pts.dy)
		{
			cumul -= (*data)->pts.dy;
			(*data)->pts.tmpx += (*data)->pts.xincr;
		}
		if ((*data)->iso && i == 2)
			fill_pixel(data, z1, z2, 0);
		else
			fill_pixel(data, z1, z2, 1);
	}
}

void		ft_bresenham(t_env **data, int z1, int z2, int i)
{
	int		cumul;

	i = 1;
	ft_init(data);
	fill_pixel(data, z1, z2, 0);
	if (!(*data)->dot && (*data)->pts.dx > (*data)->pts.dy)
	{
		cumul = (*data)->pts.dx / 2;
		while (i++ <= (*data)->pts.dx)
		{
			(*data)->pts.tmpx += (*data)->pts.xincr;
			cumul += (*data)->pts.dy;
			if (cumul >= (*data)->pts.dx)
			{
				cumul -= (*data)->pts.dx;
				(*data)->pts.tmpy += (*data)->pts.yincr;
			}
			if (i == 2)
				fill_pixel(data, z1, z2, 0);
			else
				fill_pixel(data, z1, z2, 1);
		}
	}
	else if (!(*data)->dot)
		ft_bresenham_bis(data, z1, z2);
}
