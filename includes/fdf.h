/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:55:59 by flhember          #+#    #+#             */
/*   Updated: 2019/05/10 16:16:05 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# include <stdio.h>

# define BLACK 	0x000000
# define WHITE 	0xFFFFFF
# define RED 	0xFF0000
# define ORANGE 0xFFA500
# define LIME 	0x00FF00
# define BLUE 	0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 	0x00FFFF
# define MAGENTA 0xFF00FF
# define SILVER 0xC0C0C0
# define GRAY 	0x808080
# define MAROON 0x800000
# define OLIVE 	0x808000
# define GREEN 	0x008000
# define PURPLE 0x800080
# define TEAL 	0x008080
# define NAVY 	0x000080

typedef struct		s_map
{
	int				size_line;
	int				size_col;
	int				**tab;
}					t_map;

typedef struct		s_pts
{
	int				tmpx;
	int				tmpy;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dy;
	int				dx;
	int				Dx;
	int				Dy;
	int				errx;
	int				erry;
	int				xincr;
	int				yincr;
}					t_pts;


typedef	struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned char	*img_str;
	int				decal;
	int				bpp;
	int				s_l;
	int				endian;
	struct s_pts	pts;
	struct s_map	map;
}					t_env;

int			ft_parcing(t_env **data, char *file);
void		ft_free(t_env **data, int flag);
int			ft_fdf(t_env **data, char *file);

#endif
