/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasbeer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:57:37 by hcasbeer          #+#    #+#             */
/*   Updated: 2018/01/29 15:57:37 by hcasbeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

#define ABORT abort_error(0); result.size_x = -1; result.size_y = -1;
#define SKIP_TO_NEWLINE while (str[i] != '\n' && str[i]) ++i;
#define CPY_N_INC_I while (str[i] != '\n' && str[i]) { copy[i] = str[i]; ++i; }
#define SRCH_E1 if (i < 4 || !str[i]) { ABORT; return (result); }
#define E2_TERM (str[i - 1] == str[i - 2] || str[i - 2] == str[i - 3])
#define SRCH_E2 if (E2_TERM) { ABORT; return (result); }
#define ERR1 if (!str[n]) { abort_error(0); return (NULL); }
#define ERR2 if (str[n]) { abort_error(0); return (NULL); }
#define SKIP_N_INC while (*str != '\n') { ++str; } ++str;

t_box	get_map_char(char *str)
{
	t_box	result;
	int		i;
	char	*copy;

	i = 0;
	SKIP_TO_NEWLINE;
	copy = malloc(i + 1);
	i = 0;
	CPY_N_INC_I;
	copy[i] = '\0';
	SRCH_E1;
	SRCH_E2;
	result.square_char = copy[i - 1];
	result.obstacle = copy[i - 2];
	result.fill = copy[i - 3];
	copy[i - 3] = '\0';
	result.size_y = ft_atoi(copy);
	if (result.size_y <= 0)
	{
		ABORT;
		return (result);
	}
	return (result);
}

int		get_x_size(char *str)
{
	while (*str != '\n')
		++str;
	++str;
	return (ft_strlen_until(str, '\n'));
}

char	**parse_into_array(char *str)
{
	t_box		map_s;
	char		**result;
	int			i;
	int			j;
	int			n;

	map_s = get_map_char(str);
	SKIP_N_INC;
	map_s.size_x = ft_strlen_until(str, '\n');
	i = -1;
	result = malloc(sizeof(char*) * (map_s.size_y + 1));
	n = 0;
	while (++i < map_s.size_y)
	{
		j = -1;
		result[i] = malloc(sizeof(char) * (map_s.size_x + 1));
		while (++j < map_s.size_x)
			result[i][j] = str[n++];
		ERR1;
		result[i][j] = '\0';
		++n;
	}
	ERR2;
	result[i] = NULL;
	return (result);
}
