/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:14:20 by flhember          #+#    #+#             */
/*   Updated: 2019/05/23 16:40:31 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_close(t_env **data)
{
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img_ptr);
	mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
	ft_free(data, 1);
	exit(0);
	return (0);
}
