/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:55:59 by flhember          #+#    #+#             */
/*   Updated: 2019/05/23 16:42:51 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define P 		35
# define I 		34
# define ARW_UP 126
# define ARW_DN	125
# define W 		13
# define S 		1
# define M		46
# define ARW_LT	123
# define ARW_RT	124
# define PLUS	69
# define MINUS	78
# define ESC	53
# define PTS	47
# define SLASH	44
# define ROT_X	7
# define ROT_Y	16
# define ROT_Z	6
# define PLUS2	24
# define MINUS2	27

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
	int				z1;
	int				z2;
	int				colorz1;
	int				colorz2;
	int				xincr;
	int				yincr;
}					t_pts;

typedef	struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned char	*img_str;
	int				endian;
	int				s_l;
	int				bpp;
	int				fd;
	int				margex;
	int				margey;
	int				sense_rot;
	float			incr_angl;
	float			value_aglx;
	float			value_agly;
	float			value_aglz;
	int				dot;
	int				pad;
	int				iso;
	int				zincr;
	struct s_pts	pts;
	struct s_map	map;
}					t_env;

int					ft_close(t_env **data);
int					ft_fdf(t_env **data, char *file);
int					ft_key_press(int key, t_env **data);
int					ft_parcing(t_env **data, char *file);
void				ft_menu(t_env **data);
void				ft_print_img(t_env **data);
void				ft_define_marge(t_env **data);
void				ft_print_control(t_env **data);
void				ft_free(t_env **data, int flag);
void				ft_rotation_x_y_z(t_env **data);
void				iso(t_env **data, int z1, int z2);
void				ft_bresenham(t_env **data, int z1, int z2, int i);

#endif
