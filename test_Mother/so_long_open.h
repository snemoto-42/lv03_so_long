/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:28:20 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/16 14:41:45 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 10240
# define IMG_LEN 100
# define MAP "01PCE\n"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>

typedef struct s_sl_file
{
	char	*buf;
	int		fd;
	ssize_t	n;
	size_t	col;
	size_t	row;
	char	ch;
	size_t	cnt_c;
	size_t	cnt_p;
	size_t	cnt_e;
}			t_sl_file;

typedef struct s_sl_img
{
	void	*w;
	void	*s;
	void	*c;
	void	*e;
	void	*p;
}			t_sl_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_sl_img	*img;
	t_sl_file	*info;
	char		*buf;
	int			win_w;
	int			win_h;
	int			img_len;
	size_t		flag;
	size_t		cnt_c;
	size_t		step;
	size_t		player;
	int			move;
}				t_vars;

int			sl_key_hook(int keycode, t_vars *vars);
void		*sl_make_img(void *mlx);
void		sl_put_img(char *buf, t_sl_img *img, t_vars *vars);
void		sl_exit_success(void);
void		sl_exit_failure(void);
int			sl_open(t_vars *vars);
int			sl_close(t_vars *vars);
void		sl_init(t_vars *vars, t_sl_file *info);
t_sl_file	*sl_check_file(char *file, t_sl_file *info);

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_printf(const char *format, ...);

#endif
