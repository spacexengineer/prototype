/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 00:24:20 by pthorell          #+#    #+#             */
/*   Updated: 2018/01/30 00:24:20 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "linked_list.h"
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define ABRT_AND_RET abort_error(0); return(NULL);
#define FREE free(temp); ft_list_clear(&list);
#define CLOSE_FILE(n) if (close(n) == -1) { exit(1); }
#define OPEN_FILE(n, f) n = open(f, O_RDONLY); if (n == -1) { ABRT_AND_RET };
#define M_AND_R result = malloc(ft_list_size(list) * (BUF_SIZE + 1)); rd = 0;

char		g_buf[BUF_SIZE + 1];

char	*file_to_str(char *file)
{
	char	*result;
	char	*temp;
	t_list	*list;
	int		fd;
	int		rd;

	OPEN_FILE(fd, file);
	list = NULL;
	while ((rd = read(fd, g_buf, BUF_SIZE)))
	{
		g_buf[rd] = '\0';
		temp = malloc(BUF_SIZE + 1);
		ft_strcpy(temp, g_buf);
		ft_list_push_back(&list, temp);
	}
	M_AND_R;
	while (list)
	{
		ft_strcpy(&result[rd * BUF_SIZE], list->data);
		list = list->next;
		++rd;
	}
	FREE;
	CLOSE_FILE(fd);
	return (result);
}

char	*stdin_to_str(void)
{
	char	*result;
	t_list	*list;
	int		rd;
	char	*temp;

	list = NULL;
	while ((rd = read(0, g_buf, BUF_SIZE)))
	{
		g_buf[rd] = '\0';
		temp = malloc(BUF_SIZE + 1);
		ft_strcpy(temp, g_buf);
		ft_list_push_back(&list, temp);
	}
	M_AND_R;
	while (list)
	{
		ft_strcpy(&result[rd * BUF_SIZE], list->data);
		list = list->next;
		++rd;
	}
	FREE;
	return (result);
}
