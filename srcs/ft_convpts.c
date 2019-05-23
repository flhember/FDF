/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convpts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:11:07 by flhember          #+#    #+#             */
/*   Updated: 2019/05/23 14:40:45 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotation_x(t_env **data)
{
	int prev_y1;
	int prev_y2;
	int prev_z1;
	int prev_z2;

	prev_y1 = (*data)->pts.y1;
	prev_y2 = (*data)->pts.y2;
	prev_z1 = (*data)->pts.z1;
	prev_z2 = (*data)->pts.z2;
	(*data)->pts.y1 = prev_y1 * cos((*data)->value_aglx)
		+ prev_z1 * sin((*data)->value_aglx);
	(*data)->pts.y2 = prev_y2 * cos((*data)->value_aglx)
		+ prev_z2 * sin((*data)->value_aglx);
	(*data)->pts.z1 = -prev_y1 * sin((*data)->value_aglx)
		+ prev_z1 * cos((*data)->value_aglx);
	(*data)->pts.z2 = -prev_y2 * sin((*data)->value_aglx)
		+ prev_z2 * cos((*data)->value_aglx);
}

static void	rotation_y(t_env **data)
{
	int prev_x1;
	int prev_x2;
	int prev_z1;
	int prev_z2;

	prev_x1 = (*data)->pts.x1;
	prev_x2 = (*data)->pts.x2;
	prev_z1 = (*data)->pts.z1;
	prev_z2 = (*data)->pts.z2;
	(*data)->pts.x1 = prev_x1 * cos((*data)->value_agly)
		+ prev_z1 * sin((*data)->value_agly);
	(*data)->pts.x2 = prev_x2 * cos((*data)->value_agly)
		+ prev_z2 * sin((*data)->value_agly);
	(*data)->pts.z1 = -prev_x1 * sin((*data)->value_agly)
		+ prev_z1 * cos((*data)->value_agly);
	(*data)->pts.z2 = -prev_x2 * sin((*data)->value_agly)
		+ prev_z2 * cos((*data)->value_agly);
}

static void	rotation_z(t_env **data)
{
	int prev_x1;
	int prev_x2;
	int prev_y1;
	int prev_y2;

	prev_x1 = (*data)->pts.x1;
	prev_x2 = (*data)->pts.x2;
	prev_y1 = (*data)->pts.y1;
	prev_y2 = (*data)->pts.y2;
	(*data)->pts.x1 = prev_x1 * cos((*data)->value_aglz)
		- prev_y1 * sin((*data)->value_aglz);
	(*data)->pts.x2 = prev_x2 * cos((*data)->value_aglz)
		- prev_y2 * sin((*data)->value_aglz);
	(*data)->pts.y1 = prev_x1 * sin((*data)->value_aglz)
		+ prev_y1 * cos((*data)->value_aglz);
	(*data)->pts.y2 = prev_x2 * sin((*data)->value_aglz)
		+ prev_y2 * cos((*data)->value_aglz);
}

void		iso(t_env **data, int z1, int z2)
{
	int previous_x1;
	int previous_y1;
	int previous_x2;
	int previous_y2;

	previous_x1 = (*data)->pts.x1;
	previous_y1 = (*data)->pts.y1;
	previous_x2 = (*data)->pts.x2;
	previous_y2 = (*data)->pts.y2;
	(*data)->pts.x1 = (previous_x1 - previous_y1) * cos(0.523599);
	(*data)->pts.y1 = -z1 + (previous_x1 + previous_y1) * sin(0.523599);
	(*data)->pts.x2 = (previous_x2 - previous_y2) * cos(0.523599);
	(*data)->pts.y2 = -z2 + (previous_x2 + previous_y2) * sin(0.523599);
}

void		ft_rotation_x_y_z(t_env **data)
{
	rotation_x(data);
	rotation_y(data);
	rotation_z(data);
}
