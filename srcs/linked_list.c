/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:26:08 by pthorell          #+#    #+#             */
/*   Updated: 2018/01/30 17:26:08 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *p;
	t_list *temp;

	p = ft_create_elem(data);
	temp = *begin_list;
	if (!(*begin_list))
	{
		*begin_list = p;
		return ;
	}
	while ((*begin_list)->next)
		(*begin_list) = (*begin_list)->next;
	(*begin_list)->next = p;
	*begin_list = temp;
}

int		ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		++i;
	}
	return (i);
}

void	ft_list_clear(t_list **begin_list)
{
	t_list *p;
	t_list *next;

	p = (*begin_list);
	while (p)
	{
		next = p->next;
		free(p);
		p = next;
	}
	free(*begin_list);
}
