/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:37:04 by flhember          #+#    #+#             */
/*   Updated: 2019/05/10 18:07:48 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void fill_pixel(t_env **data, int x, int y, int z)
{
	int pixel;

	//pixel = (4 * x * 30) + (4 * 1920 * y * 30);
	pixel = x + y;
	if (pixel < ((1920 * 1080) * 4))
	{
		if (z == 0)
		{
			(*data)->img_str[pixel] = 0;
			(*data)->img_str[pixel + 1] = 255;
			(*data)->img_str[pixel + 2] = 0;
		}
		else
		{
			(*data)->img_str[pixel] = 0;
			(*data)->img_str[pixel + 1] = 0;
			(*data)->img_str[pixel + 2] = 255;
		}
	}
}

static void	ft_bresenham (t_env **data)
{
		int		i;
	
		(*data)->pts.tmpx = (*data)->pts.x1;
		(*data)->pts.tmpy = (*data)->pts.y1;
		(*data)->pts.errx = abs((*data)->pts.x2 - (*data)->pts.x1);
		(*data)->pts.erry = abs((*data)->pts.y2 - (*data)->pts.y1);
		(*data)->pts.dx = 2 * (*data)->pts.errx;
		(*data)->pts.dy = 2 * (*data)->pts.erry;
		(*data)->pts.Dx = (*data)->pts.errx;
		(*data)->pts.Dy = (*data)->pts.erry;
		(*data)->pts.xincr = 4;
		(*data)->pts.yincr = 4;
		i = 0;
		if ((*data)->pts.x1 > (*data)->pts.x2)
			(*data)->pts.xincr = -4;
		if ((*data)->pts.y1 > (*data)->pts.y2)
			(*data)->pts.yincr = -4;
		if ((*data)->pts.Dx >= (*data)->pts.Dy)
		{
			while (i < (*data)->pts.Dx)
			{
				printf("oui");
				fill_pixel(data, (*data)->pts.tmpx, (*data)->pts.tmpy, 0);
				i++;
				(*data)->pts.tmpx += (*data)->pts.xincr;
				(*data)->pts.errx -= (*data)->pts.dy;
				if ((*data)->pts.errx < 0)
				{
					printf("non");
					(*data)->pts.tmpy += (*data)->pts.yincr;
					(*data)->pts.errx += (*data)->pts.dx;
				}
			}
		}
		else if ((*data)->pts.Dy > (*data)->pts.Dx)
		{
			printf("ap");
			//while (i <= (*data)->pts.Dy)
			while ((*data)->pts.tmpy != (*data)->pts.y2)
			{
				fill_pixel(data, (*data)->pts.tmpx, (*data)->pts.tmpy, 0);
				i++;
				(*data)->pts.tmpy += 1920;//(*data)->pts.yincr;
				(*data)->pts.erry -= (*data)->pts.dx;
				if ((*data)->pts.erry < 0)
				{
					printf("non");
					(*data)->pts.tmpx += 1920;//(*data)->pts.xincr;
					(*data)->pts.erry += (*data)->pts.dy;
				}
			}
		}
		printf("\n");
}

static int	ft_filling_img_line(t_env **data)
{
	int		y;
	int		x;

	y = 1;
	(*data)->pts.y2 = (4 * 1920 * y) * (*data)->decal;
	(*data)->pts.y1 = (4 * 1920 * y) * (*data)->decal;
	while (y <= (*data)->map.size_col)
	{
		x = 1;
		(*data)->pts.x1 = (4 * x) * (*data)->decal;
		(*data)->pts.x2 = (4 * (x + 1)) * (*data)->decal;
		while (x + 1 <= (*data)->map.size_line)
		{
		//	printf("x = %d, %d\n", x, (*data)->map.size_line);
			ft_bresenham(data);
			fill_pixel(data, (*data)->pts.x1, (*data)->pts.y1, 10);
			fill_pixel(data, (*data)->pts.x2, (*data)->pts.y2, 10);
			x++;
			(*data)->pts.x1 = (*data)->pts.x2;
			(*data)->pts.x2 = (4 * (x + 1)) * (*data)->decal;
		}
		y++;
		(*data)->pts.y2 = (4 * 1920 * y) * (*data)->decal;
		(*data)->pts.y1 = (*data)->pts.y2;
	}
	return (1);
}

static int	ft_filling_img_col(t_env **data)
{
	int		y;
	int		x;

	x = 1;
	(*data)->pts.x2 = (4 * x) * (*data)->decal;
	(*data)->pts.x1 = (4 * x) * (*data)->decal;
	while (x <= (*data)->map.size_line)
	{
		y = 1;
		(*data)->pts.y1 = (4 * 1920 * y) * (*data)->decal;
		(*data)->pts.y2 = (4 * 1920 * (y + 1)) * (*data)->decal;
		while (y <= (*data)->map.size_col)
		{
			printf("y = %d, %d\n", y, (*data)->map.size_col);
			ft_bresenham(data);
			fill_pixel(data, (*data)->pts.x1, (*data)->pts.y1, 10);
			fill_pixel(data, (*data)->pts.x2, (*data)->pts.y2, 10);
			y++;
			(*data)->pts.y1 = (*data)->pts.y2;
			(*data)->pts.y2 = (4 * 1920 * (y + 1)) * (*data)->decal;
		}
		x++;
		(*data)->pts.x2 = (4 * x) * (*data)->decal;
		(*data)->pts.x1 = (4 * x) * (*data)->decal;
	}
	return (1);
}

static int	ft_image_mlx(t_env **data)
{
	(*data)->img_ptr = mlx_new_image((*data)->mlx_ptr, 1920, 1080);
	(*data)->img_str = (unsigned char*)mlx_get_data_addr((*data)->img_ptr,
			&(*data)->bpp, &(*data)->s_l, &(*data)->endian);
	ft_filling_img_line(data);
	ft_filling_img_col(data);
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr, (*data)->img_ptr, 0, 0);
	return (0);
}

int		ft_fdf(t_env **data, char *file)
{
	if (!(ft_parcing(data, file)))
		return (0);
	(*data)->decal = 30;
	(*data)->mlx_ptr = mlx_init();
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr, 1920, 1080, "fdf");
	ft_image_mlx(data);
	mlx_loop((*data)->mlx_ptr);
	return (1);
}
