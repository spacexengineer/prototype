/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasbeer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:05:27 by hcasbeer          #+#    #+#             */
/*   Updated: 2018/01/29 16:05:27 by hcasbeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_box {
	char		fill;
	char		obstacle;
	char		square_char;
	int			size_y;
	int			size_x;
}				t_box;

typedef struct	s_point {
	int			x;
	int			y;
}				t_point;

void			ft_putchar(char c);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
int				get_largest_square(char **map, t_box map_char, t_point point);
void			print_square_solution(char **map, int size,
										t_box map_char, t_point point);
t_point			get_largest_square_on_map(char **map, t_box map_char);
int				ft_strlen_until(char *str, char c);
char			*file_to_str(char *file);
t_box			get_map_char(char *str);
int				get_x_size(char *str);
char			**parse_into_array(char *str);
void			abort_error(int code);
char			*ft_strcpy(char *dest, char *str);
char			*stdin_to_str(void);
int				ft_atoi(char *str);

#endif
