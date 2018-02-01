/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:47:49 by pthorell          #+#    #+#             */
/*   Updated: 2018/01/28 20:47:49 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 7)
		return (0);

	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int density = atoi(argv[3]);
	char map = argv[4][0];
	char obs = argv[5][0];
	char ans = argv[6][0];
	
	srand(time(NULL));

	printf("%i%c%c%c\n", y, map, obs, ans);
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			if ((rand() % y) * 2 < density)
				putchar(obs);
			else
				putchar(map);
		}
		putchar('\n');
	}
	return (0);
}
