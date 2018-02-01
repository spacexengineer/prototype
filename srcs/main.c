/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 01:56:44 by pthorell          #+#    #+#             */
/*   Updated: 2018/01/30 01:56:44 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

#define SET_TEMP temp = get_largest_square(map_a, map_box, point);
#define PRINT_SQUARE print_square_solution(map_a, temp, map_box, point);
#define TEST_0 if (point.x != -1) { SET_TEMP; PRINT_SQUARE; }
#define TEST_1 if (map_a) { TEST_0 }
#define SET_POINT point = get_largest_square_on_map(map_a, map_box)
#define FINAL_STUFF SET_POINT; TEST_0;
#define FINAL_THINGS free(map); if (map_a) { FINAL_STUFF }
#define ELSE_ERROR else abort_error(0);

int g_i;

int		main(int argc, char **argv)
{
	t_point		point;
	t_box		map_box;
	char		*map;
	char		**map_a;
	int			temp;

	g_i = (argc == 1 ? 0 : 1);
	while (g_i < argc)
	{
		map = (g_i == 0 ? stdin_to_str() : file_to_str(argv[g_i]));
		if (map)
		{
			map_box = get_map_char(map);
			if ((map_box.size_y > 0) && (map_box.size_x = get_x_size(map)))
			{
				if ((map_box.size_x > 0) && (map_a = parse_into_array(map)))
				{
					FINAL_THINGS;
				}
				ELSE_ERROR;
			}
		}
		++g_i;
	}
	return (0);
}
