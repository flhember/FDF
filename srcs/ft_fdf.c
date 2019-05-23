/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:37:04 by flhember          #+#    #+#             */
/*   Updated: 2019/05/23 16:30:27 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_menu(t_env **data)
{
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 945, 80, 0xE2EDEC
			, "FDF");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 500, 200, 0xE2EDEC
			, "Press 'i' to view isometric");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 1150, 200, 0xE2EDEC
			, "Press 'p' to view parallel");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 1600, 1000, 0xE2EDEC
			, "Press 'esc' to quit");
}

void	ft_print_control(t_env **data)
{
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 10, 10, 0xE2EDEC
			, "'i' to view isometric");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 10, 30, 0xE2EDEC
			, "'p' to view parallel");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 10, 50, 0xE2EDEC
			, "Move Map: Direction Arrow");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 10, 70, 0xE2EDEC
			, "Rot Map: 'x' 'y' 'z', '=' to + and '-' to -");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 10, 90, 0xE2EDEC
			, "zoom +: 'w' Zoom -: 's'");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 10, 110, 0xE2EDEC
			, "Without bresenham '.', whith bresenham '/'");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 10, 130, 0xE2EDEC
			, "increase '+' or decrease '-' z");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 10, 150, 0xE2EDEC
			, "'m' to menu");
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 1600, 1000, 0xE2EDEC
			, "Press 'esc' to quit");
}

void	ft_define_marge(t_env **data)
{
	int		tmpx;
	int		tmpy;

	tmpx = ((*data)->map.size_line / 2) * (*data)->pad;
	tmpy = ((*data)->map.size_col / 2) * (*data)->pad;
	(*data)->margex = (1920 / 2) - tmpx;
	(*data)->margey = (1080 / 2) - tmpy;
}

int		ft_fdf(t_env **data, char *file)
{
	if (!(ft_parcing(data, file)))
		return (0);
	(*data)->pad = 30;
	(*data)->mlx_ptr = mlx_init();
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr, 1920, 1080, "fdf");
	mlx_hook((*data)->win_ptr, 2, 0, ft_key_press, data);
	mlx_hook((*data)->win_ptr, 17, 0, ft_close, data);
	ft_menu(data);
	mlx_loop((*data)->mlx_ptr);
	return (1);
}
