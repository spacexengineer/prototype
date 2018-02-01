/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:11:55 by pthorell          #+#    #+#             */
/*   Updated: 2018/01/29 19:11:55 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define OOB_POINT	(p.y + i >= map_c.size_y || p.x + j >= map_c.size_x)
#define OBS_POINT	(map[p.y + i][p.x + j] == map_c.obstacle)
#define CHECK_VALID	if (OOB_POINT || OBS_POINT) return (size);
#define INIT_VAR 	i = 0; j = 0; size = 0;
#define ABRT_PRC	abort_error(0); temp.x = -1; temp.y = -1; return (temp);
#define OBS_CHECK	(map[i][j] != map_char.obstacle)
#define FILL_CHECK	(map[i][j] != map_char.fill)
#define TEMP_INIT   temp.x = j; temp.y = i;
#define LAR_SQ      get_largest_square(map, map_char, temp)
#define INT_INIT    i = 0; max = 0;

int			get_largest_square(char **map, t_box map_c, t_point p)
{
	int i;
	int j;
	int size;

	INIT_VAR;
	CHECK_VALID;
	size = 1;
	while (size < map_c.size_x)
	{
		i = size;
		j = -1;
		while (++j < i)
			CHECK_VALID;
		i = -1;
		j = size;
		while (++i <= j)
			CHECK_VALID;
		++i;
		++size;
	}
	return (size);
}

void		print_square_solution(char **map, int size, t_box map_c, t_point p)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[p.y + i][p.x + j] = map_c.square_char;
			++j;
		}
		++i;
	}
	while (*map)
	{
		ft_putstr(*map);
		ft_putstr("\n");
		++map;
	}
}

int			larger_then_assign(int a, int *b, t_point *result, t_point *temp)
{
	if (a > *b)
	{
		*b = a;
		(*result) = (*temp);
		return (1);
	}
	else
		return (0);
}

t_point		get_largest_square_on_map(char **map, t_box map_char)
{
	int		i;
	int		j;
	int		max;
	t_point	result;
	t_point	temp;

	INT_INIT;
	while (i < map_char.size_y)
	{
		j = 0;
		while (j < map_char.size_x)
		{
			TEMP_INIT;
			if (larger_then_assign(LAR_SQ, &max, &result, &temp))
				if (max == map_char.size_x)
					return (result);
			++j;
		}
		if (map_char.size_y - i <= max)
			return (result);
		++i;
	}
	return (result);
}
