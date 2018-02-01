/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:54:08 by pthorell          #+#    #+#             */
/*   Updated: 2018/01/30 17:54:08 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdio.h>

typedef struct	s_list
{
	struct s_list	*next;
	char			*data;
}				t_list;

void			ft_list_push_back(t_list **begin_list, void *data);
int				ft_list_size(t_list *begin_list);
void			ft_list_clear(t_list **begin_list);

#endif
