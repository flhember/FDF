/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:17:04 by flhember          #+#    #+#             */
/*   Updated: 2019/05/23 16:42:49 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_key_move_arw(int key, t_env **data)
{
	if (key == ARW_UP)
		(*data)->margey -= 10;
	else if (key == ARW_DN)
		(*data)->margey += 10;
	else if (key == ARW_LT)
		(*data)->margex -= 10;
	else if (key == ARW_RT)
		(*data)->margex += 10;
}

static void	ft_key_reset(int key, t_env **data)
{
	if (key == I)
		(*data)->iso = 1;
	else if (key == P)
		(*data)->iso = 0;
	(*data)->value_aglx = 0;
	(*data)->value_agly = 0;
	(*data)->value_aglz = 0;
	(*data)->pad = 30;
	(*data)->zincr = 0;
	ft_define_marge(data);
	ft_print_img(data);
}

static void	ft_key(int key, t_env **data)
{
	if (key == PTS)
		(*data)->dot = 1;
	if (key == SLASH)
		(*data)->dot = 0;
	if (key == W)
		(*data)->pad += 5;
	if (key == S)
		if ((*data)->pad > 5)
			(*data)->pad -= 5;
	if (key == PLUS)
		(*data)->zincr += 5;
	if (key == MINUS)
		(*data)->zincr -= 5;
}

static void	ft_key_rot(int key, t_env **data)
{
	if (key == ROT_X)
		(*data)->value_aglx += (*data)->incr_angl;
	if (key == ROT_Y)
		(*data)->value_agly += (*data)->incr_angl;
	if (key == ROT_Z)
		(*data)->value_aglz += (*data)->incr_angl;
}

int			ft_key_press(int key, t_env **data)
{
	if (key == P || key == I)
		ft_key_reset(key, data);
	if (key == ARW_UP || key == ARW_DN || key == ARW_LT || key == ARW_RT)
		ft_key_move_arw(key, data);
	if (key == PTS || key == SLASH || key == W || key == S || key == PLUS
			|| key == MINUS)
		ft_key(key, data);
	if (key == MINUS2)
		(*data)->incr_angl = -0.05;
	if (key == PLUS2)
		(*data)->incr_angl = 0.05;
	if (key == ROT_X || key == ROT_Y || key == ROT_Z || key == MINUS2
			|| key == PLUS2)
		ft_key_rot(key, data);
	if (key == ESC)
	{
		mlx_destroy_image((*data)->mlx_ptr, (*data)->img_ptr);
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
		ft_free(data, 1);
		exit(0);
	}
	ft_print_img(data);
	return (0);
}
